*This project has been as part of the 42 curriculum by kagoh*

## Table of Contents
1. [Description](#description)
2. [Instructions](#instructions)
3. [Resources](#resources)
4. [Project Description](#project-description)
5. [Project Flow](#project-flow)

## Description
Inception is a systems administration project that introduces the student to Docker containerization, with the goal of having the student create a simple infrastructure consisting of different services, with each service running in its own container.

The project implements a full web stack which consists of:
1. **Nginx**: web server with TLSv1.2/1.3 encryption protocols
2. **Mariadb**: database server
3. **Wordpress**: content management system with PHP-FPM

All services should be built from scratch with individual Dockerfiles for each service, with no prebuilt services (e.g. `wordpress:latest`). The services should communicate through a Docker network, and data should also persist using bind mounts.

## Instructions

### Prerequisites
The following should be present:
- Docker and Docker Compose
- GNU Make
- Linux-based system (Penultimate version Debian/Alpine)

Note: The evaluation should be carried out in a VM on the evaluatee's terminal. As such, all of these should be present in the VM at the point of evaluation.

### Setup, Compilation and Execution
**Cloning the project**
```
git clone <repository_url> [directory_name]
```
**Compiling and Running Project**
```
make
# or 
make up
```
**Accessing the Website**
```
https://<login>.42.fr

# for logging on with administrator and user profiles
https://<login>.42.fr/wp-admin
```
All other relevant testing and evaluation should happen in the VM.

### Verification of Project
Check all containers are running and none are in "Restarting" status:
```
docker ps

#or
make status
```

View container logs:
```
docker logs <container_name>
```

## Resources
The following resources were utilized in the course of this project:
1. Google (Stack Overflow, general enquiries on project)
2. Youtube tutorials (Docker basics, containerization etc.)
3. [Docker Documentation](https://docs.docker.com/)
4. [Docker Compose Documentation](https://docs.docker.com/compose/)
5. [Nginx Documentation](https://nginx.org/en/docs/)
6. [Mariadb Documentation](https://mariadb.com/docs)
7. [Wordpress Documentation](https://wordpress.org/documentation/)

### AI Usage
AI was used as a learning and debugging aid in the development of this project.

Ways that AI was utilized:

- Understanding concepts about Docker (networks, volumes, bind mounts), and only utilized if not immediately understood through self-learning
- Understanding how the containers communicate with each other
- Minor formatting for documentation(DEV_DOC, USER_DOC, README), such as how to make code blocks, how to italicize text etc.
- General enquiries, such as "How do i test my nginx container to see if it's working?"
- Used as a springboard into coding out the actual document e.g. "what should the docker compose yaml file look like?"

AI did not generate the entire project, but rather was used as an aid for understanding concepts that might not have been underestood immediately through Google search or Youtube tutorials. Final implementation decisions were made by the developer.

## Project Description

### Overview
Docker was used in this project to easily create isolated environments that can be replicated across systems for each of the services required in this project in a standardized unit or package called a container.

Docker allows:
- Packaging of the service with its dependencies
- Ensure that the behaviour of the service is consistent across different systems
- Isolate services from each other and the host, therefore preventing conflicts between containers and their dependencies. Isolation also limits access to the host resources, thus enhancing security.
- Manage the entire infrastructure more efficiently

**Docker images built**:
1. Nginx: Web server and serves as the reverse proxy, handling HTTP requests
2. Mariadb: Database storing information on Wordpress users and their corresponding data
3. Wordpress + PHP-FPM: Content management system

Images are constructed using a docker compose file, which manages their lifecycle, networks and data storage in volumes.

**Other sources in the project**:
- Dockerfiles: Defines how each image is built, with the relevant dependencies to be installed and other relevant instructions.
- Configuration files: files for configuring settings of the individual services, like nginx and wordpress.
- Setup scripts: scripts to automate setup of each indicvidual service.
- `.env` file: Stores non-sensitive configurations and variables
- `docker-compose.yml` file: constructs images and connects all services together
- `secrets/` folder: for storage of passwords and other sensitive configurations.

### Virtual Machines vs Docker
| Area of Comparison | Virtual Machines | Docker |
| ---- | ---------------- | ------ |
| What it is | Complete OS with hypervisor | Containers sharing resources from the host | 
| Startup Time | Minutes | Seconds | 
| Resource Usage | Heavy; drawing from host resources | Light |
| Isolation/Security | Complete isolation; strong security | Moderate isolation, normally at process level |

Why Docker was chosen:
- Efficiency: Containers start almost immediately, and require less resources to run and start up, making it ideal for development
- Portability: Services can be ported in between different systems, eliminating the problem of "This works on my machine"

Docker is also chosen because multiple isolated services are going to be run on a machine, and using a VM would be too much for just these services.

### Secrets vs Environment Variables

| Area of Comparison | Environment Variables | Secrets |
| ------------------ | --------------------- | ------- |
| Where it is stored | `.env` file | separate encrypted files/folders |
| Visibility and Security | Visible in logs | Hidden from logs |
| Purpose | Application configurations, features, non-sensitive settings | Sensitive configurations like passwords, API keys etc. |
| Accessibility | As environment variables | As files in `run/secrets/` |

For the purposes of this project, both need to be present, with environment variables being stored in `.env` file in directory root and a separate `secrets` folder.

**In docker compose file**:
Example of how secrets can be accessed in the docker compose file:
```
secrets:
  db_password:
    file: ./secrets/db_password.txt
  wp_admin_password:
    file: ./secrets/wp_admin_password.txt

 mariadb:
    secrets:
      - db_password
```

How scripts read from secrets folder:
```
DB_PASSWORD=$(cat /run/secrets/db_password)
```

This helps to ensure that passwords are not exposed in container logs.

### Docker Network vs Host Network
| Area of Comparison | Docker Network | Host Network |
| ------------------ | -------------- | ------------ |
| Network isolation | Isolated network, with its own IP address and network namespace | Uses host's network directly | 
| Security | Only exposed via ports | Exposed to the host network | 
| Port Access | Requires explicit port mapping | Ports exposed by the container are bound to the same port on host IP; no mapping needed | 
| Conflicts | No conflict; multiple containers can bind to the same port as long as host ports are different | Only 1 process can bind to a specific port at a time; potential for conflicts |

Docker network was chosen because of:
- Network isolation: services communicate only through the defined network
- Security: Sensitive containers like mariadb are not exposed to the host network, only to the other containers
- Flexibility: scalable; able to add other containers when needed

**How Docker network is used**:
```
networks:
  inception:
    driver: bridge

wordpress:
      - wordpress_files:/var/www/html
    networks:
      - inception
```

Thus, wordpress can connect to mariadb via `mariadb:3306` as the hostname, making configuration more simple.

### Docker Volumes vs Bind Mounts
| Area of Comparison | Docker Volumes | Bind Mounts |
| ------------------ | -------------- | ----------- |
| File Locations | Stored in a docker-specified path | Storred in a user-specified path |
| Management | Managed by Docker and API | Managed by host machine's OS and file system |
| Portability | More portable across different systems | Not easily portable, as path must exist on host machine |
| Visibililty | Hidden from host | Directly visible |

Bind mounts are chosen because:
- Project requirement: project requires data to be stored in a specific directory (`home/login/data/wordpress`)
- Accessibililty and Transparency: It is more clear where files are being stored due to the existence of absolute path, thus making it easier to view and edit data.
- Simplicity: only standard file operations are needed for this project.

**How bind mount is used**:
```
volumes: 
  wordpress_files: 
    driver: local 
    driver_opts: 
      type: none 
      o: bind 
      device: /home/login/data/wordpress
```

This mounts host directory onto container directly, so that it is accessible in `/home/kagoh/data/wordpress`. Data will also persist even when containers are removed, and can be easily backed up via standard tools.

## Project Flow

### Project Directory Structure

```
inception/
├── DEV_DOC.md
├── Makefile
├── README.md
├── srcs
│   ├── docker-compose.yml
│   ├── requirements
│   │   ├── mariadb
│   │   │   ├── 50-server.conf
│   │   │   ├── db_setup.sh
│   │   │   └── Dockerfile
│   │   ├── nginx
│   │   │   ├── default.conf
│   │   │   └── Dockerfile
│   │   └── wordpress
│   │       ├── Dockerfile
│   │       └── wp_setup.sh
│   └── secrets
│       ├── db_password.txt
│       ├── wp_admin_password.txt
│       └── wp_user_password.txt
└── USER_DOC.md
```

### Infrastructure Flow
```
User (HTTPS) -> Nginx (443) -> Wordpress (9000) -> Mariadb (3306)
              /var/www/html     /var/www/html      /var/lib/mysql
                  |                 |                   |
              Bind Mount       Bind Mount          Bind Mount
                  |                 |                   |
             /home/<login>data/wordpress    /home/<login>/data/mariadb
```

1. User accesses the website via `https://<login>.42.fr"
2. Nginx container handles the HTTP request and forwards PHP request to Wordpress via FastCGI
3. Wordpress processes the request and queries Mariadb for the relevant information
4. All containers communicate through the `inception` network
5. Data should persist on the host even when containers are removed
