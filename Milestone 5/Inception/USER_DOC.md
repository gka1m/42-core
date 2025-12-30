# User Documentation
This document explains how to compile and run the project, for more clarity and to ensure a smoother process in the evaluation

---

## Services Provided
The project deploys a containerized web stack with the use of Docker. <br>
The stack has the following features:
1. NGINX: 
    - Acts as the web server and reverse proxy
    - Handles HTTPS connections using either TLS 1.2/1.3 protocols
    - Accessible only on port 443
    - Serves static files and forwards PHP requests to Wordpress

2. Mariadb: 
    - Stores the Wordpress data, such as users, posts and configurations
    - Runs on port 3306 (internal network)
    - Data persists in `/home/<login>/data/mariadb`

3. Wordpress + PHP-FPM: 
    - For website and content management. (e.g. creating/deleting posts, approving comments etc.) 
    - Processes PHP requests over port 9000
    - Data can be found in `/home/<login>/data/wordpress`

## Starting/Stopping the project
To start the project, after cloning and navigating to the repository, run:
```
make up
```
This will compile the project and build the containers and the respective directories that data should be nested in.

To stop containers without removing the volumes, run:
```
make down
```

To stop and remove the volumes, run the following command:
```
make clean
```
For a full system clean, including removal of Docker images and local data directories after evaluation, run:
```
make fclean
```

## Accessing the website
The website for the server can be accessed at the following link:<br>
https://login.42.fr

Replace ```<login>``` with the intranet name of the student being evaluated.
There should be a warning from the browser about a self-signed SSL certificate.

## Locate and Manage Credentials
To access the admin panel, navigate to the following:
```
https://<login>.42.fr/wp-admin
```
Login with the administrator credentials provided in the repository. <br>
From the admin panel, you can:
1. Create and manage posts
2. Approve/moderate comments posted by other users
3. Manage users
4. Configure site settings
### Credential locations
Credentials are mainly stored in 2 places:
1. Environment variables (non-sensitive configurations)
```
.env
```
- stores domain name, database name, wordpress and admin usernames.

2. Secrets (sensitive configurations)
```
/srcs/secrets/
```
- stores passwords for logging in to databases and wordpress as the admin/user.

## Check Service Status
To view the status of the docker containers, run either of the 2 commands:
```
docker ps
make status
```
None of the containers should be showing the "restarting" status.

To view the error logs of each container, run:
```
docker logs <container name>
```
for example:
```
docker logs mariadb
```