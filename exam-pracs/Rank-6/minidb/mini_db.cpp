#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>

/* ================= SOCKET ================= */

class Socket {
private:
    int _fd;
    struct sockaddr_in addr;

public:
    Socket() : _fd(-1) {}

    ~Socket()
    {
        if (_fd != -1)
            close(_fd);
    }

    void create(int port)
    {
        _fd = socket(AF_INET, SOCK_STREAM, 0);
        if (_fd < 0)
            exit(1);

        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
        addr.sin_port = htons(port);
    }

    void listenAndBind()
    {
        if (bind(_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
            exit(1);
        if (listen(_fd, 128) < 0)
            exit(1);
    }

    int acceptClient()
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
        return accept(_fd, (struct sockaddr *)&client, &len);
    }

    int fd() const { return _fd; }
};

/* ================= SERVER ================= */

class Server {
private:
    Socket sock;
    fd_set master;
    fd_set readfds;
    int maxfd;

    /* mine */
    std::map<std::string, std::string> db;
    /* end of mine */

public:

    /* mine */
    void load()
    {
        std::ifstream in(".save");
        std::string key;
        std::string val;

        while (in >> key)
        {
            std::getline(in, val);
            if (!val.empty() && val[0] == ' ')
                val.erase(0, 1);
            db[key] = val;
        }
    }

    void save()
    {
        std::ofstream out(".save");
        for (std::map<std::string, std::string>::iterator it = db.begin(); it != db.end(); it++)
            out << it->first << " " << it->second << std::endl;
    }

    void handlecmd(int fd, const std::string &line)
    {
        std::stringstream ss(line);
        std::string cmd, key, val;

        ss >> cmd >> key;
        if (cmd == "POST")
        {
            std::getline(ss, val);
            if (!val.empty() && val[0] == ' ')
                val.erase(0, 1);
        }
        else if (cmd == "GET")
        {
            if (db.count(key))
            {
                std::string out = "0 " + db[key] + "\n";
                send(fd, out.c_str(), out.size(), 0);
            }
            else
                send(fd, "1\n", 2, 0);
        }
        else if (cmd == "DELETE")
        {
            if (db.erase(key))
                send(fd, "0\n", 2, 0);
            else
                send(fd, "1\n", 2, 0);
        }
    }
    /* end of mine */

    void run(int port)
    {
        try
        {
            /* mine */
            sock.create(port);
            /* end of mine */
            sock.listenAndBind();
            /* mine */
            load();
            write(1, "ready\n", 6);
            /* end of mine */

            FD_ZERO(&master);
            FD_SET(sock.fd(), &master);
            maxfd = sock.fd();

            while (1)
            {
                readfds = master;
                if (select(maxfd + 1, &readfds, NULL, NULL, NULL) < 0)
                    continue;
                
                /* mine */
                for (int fd = 0; fd <= maxfd; fd++)
                {
                    if (!FD_ISSET(fd, &readfds))
                        continue;
                    if (fd == sock.fd())
                    {
                        int client = sock.acceptClient();
                        if (client >= 0)
                        {
                            FD_SET(client, &master);
                            if (client > maxfd)
                                maxfd = client;
                        }
                    }
                    else
                    {
                        char buffer[1024];
                        int ret = recv(fd, buffer, 1023, 0);

                        if (ret <= 0)
                        {
                            close(fd);
                            FD_CLR(fd, &master);
                            save();
                        }
                        else
                        {
                            buffer[ret] = 0;
                            std::stringstream ss(buffer);
                            std::string line;
                            while (std::getline(ss, line))
                            {
                                if (!line.empty())
                                    handlecmd(fd, line);
                            }
                        }
                    }
                }
                /* end of mine */
            }
        }
        catch (...)
        {
            exit(1);
        }
    }
};

/* ================= MAIN ================= */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        return 1;
    }

    Server server;
    server.run(atoi(argv[1]));
    return 0;
}
