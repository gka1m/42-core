# Developer Documentation
This document presents the prerequisites on how to set up and build the project from scratch. The document also provides ways to debug/troubleshoot the project.

---
## Table of Contents

1. [Environment Setup](#environment-setup)
2. [Project Structure](#project-structure)
3. [Building and Launching](#building-and-launching)
4. [Container Management](#container-management)
5. [Volume Management](#volume-management)
6. [Debugging and Troubleshooting](#debugging-and-troubleshooting)
7. [Development Workflow](#development-workflow)

## Environment Setup

### Required Software
The following software are needed in order to get started:
1. Docker Engine
2. Docker Compose
3. GNU Make
4. Linux-based environment (Penultimate stable version of Debian at time of project commencement)

**Installation**:
```
sudo apt-get update
sudo apt-get install docker docker-compose make

# add user to docker group for permission settings
sudo usermod -aG docker $USER
# log out and back in for changes to take effect
```

### Files
Create a .env file in the srcs folder to add in environment variables.

Example variables in .env file:
```
MARIADB_DATABASE = wordpress
DOMAIN_NAME = login.42.fr
```
### Secrets Folder
Create the secrets directory and the password files:
```
mkdir -p secrets
```

Examples of files in secrets:
1. Database password
2. Administrator wordpress password
3. User wordpress password

### Data Directories
The project requires 2 directories for data persistence:

```
/home/<login>/data/
├── mariadb/      # Database files
└── wordpress/    # WordPress files

mkdir -p /home/login/data/wordpress
mkdir -p /home/login/data/mariadb
```

Remember to set the required permissions for the directories.
```
chmod +x <path to file>
```

## Project Structure

Example folder structure of the project is as shown below:

```
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

Add in folders for the individual requirements when necessary, and structure the directories as you see fit.

## Building and Launching Project

### Makefile Rules
Makefile provides rulesets for your own convenience in managing the project:
```
# build and start all services
make up
make

# stop services, but keep the volumes
make down

# full cleanup (removes everything including images and data)
make fclean

# Rebuild after changing environment variables/secrets
make rebuild

# restart containers
make restart

# View status of all containers
make status
```

### Manual Docker Compose Commands
If you need more control, or wanting to focus on one container at a time:
```
# Build images without starting the containers
docker-compose -f srcs/docker-compose.yml build

# Start without cache (force rebuild)
docker-compose -f srcs/docker-compose.yml build --no-cache

# Start services in foreground 
docker-compose -f srcs/docker-compose.yml build up

# Start services in background
docker-compose -f srcs/docker-compose.yml build up -d

# Stop services
docker-compose -f srcs/docker-compose.yml down

# Stop and remove volumes
docker-compose -f srcs/docker-compose.yml down -v

# View logs
docker-compose -f srcs/docker-compose.yml logs (add -f flag for real time logs)

# Rebuild specific service
docker-compose -f srcs/docker-compose.yml build nginx
docker-compose -f srcs/docker-compose.yml up -d nginx
```

## Container Management

### View Container Status
```
# List all running containers
docker ps

# List all containers (including those that are stopped)
docker ps -a

# Show resource usage stats for containers
docker stats

# Inspect specific container
docker inspect
```

### Container Logs
```
# View all logs
docker logs (add -f for real time logs, -t for timestamps)

# Show last N lines
docker logs --tail N

# View specific container logs 
docker logs <container_name>
```

### Executing Commands in Containers
```
# Interactive shell
docker exec -it bash (or sh)

# Run single command
docker exec

# Examples
docker exec mariadb mysql -u root -p
```

### Restarting Containers
```
# Restart one container
docker restart

# Restart all services
docker-compose -f srcs/docker-compose.yml restart
```

## Volume Management

### Data Persistence
The project uses bind mounts to persist data:

| Service | Container Path | Host Path |
| --------| ---------------| ----------|
| Wordpress | `var/www/html` | `home/<login>/data/wordpress` |
| Mariadb | `var/lib/mysql ` | `home/<login>/data/mariadb` |

Data survives container restarts and removals unless `make fclean` is used.

### View Volume Contents
```
# View files of a container
ls -la /home/<login>/data/<container_name>

# note: for mariadb, it requires sudo permissions
```

### Accessing Database
```
# Access Mariadb CLI
docker exec -it mariadb mysql -u root -p

# Access with password from secrets
docker exec -it mariadb mysql -u root -p$(cat srcs/secrets/db_password.txt)

# Run SQL query
docker exec mariadb mysql -u root wordpress -e "SELECT * FROM wp_users;"
```

## Debugging and Troubleshooting
### Check Service Status
```
# Verify all containers are running
docker ps
make status

# Check specific logs for a service
docker logs <container_name>
# e.g docker logs wordpress
```

### Common Issues
#### Container Not Starting
```
# Check logs
docker ps
docker logs <container_name>

# Rebuild containers
make rebuild
```

#### Database Connection
```
# Verify MariaDB is running
docker ps | grep mariadb

# Test database connection
docker exec mariadb mysqladmin ping -h localhost -u root

# Check if WordPress can reach MariaDB
docker exec wordpress ping -c 3 mariadb
```

#### Permission Issues
```
# Fix WordPress permissions
docker exec wordpress chown -R www-data:www-data /var/www/html

# Fix Mariadb permissions
sudo chown -R mysql:mysql /var/run/mysqld
```

### Network Debugging
```
# Inspect Docker network
docker network inspect srcs_inception

# Check connectivity between containers
docker exec wordpress nc -zv mariadb 3306
```

### Wordpress Debugging
```
# Check WordPress installation
docker exec wordpress wp core is-installed --allow-root

# List WordPress users
docker exec wordpress wp user list --allow-root

# Verify database connection
docker exec wordpress wp db check --allow-root
```

## Development Workflow
### Making Changes

**After modifying Dockerfile**:
```
make rebuild
```
**After modifying configuration files**:
```
make fclean
make up
```
### Testing Changes
Always test with clean installation:
```
make fclean
make up
docker ps
docker logs <container_name>
```

### Verification Checklist
- All three containers are running (`docker ps`)
- No containers should be in "Restarting" status
- Mariadb shows "Ready for connection" in logs
- Wordpress installation completed successfully
- Both Wordpress users should exist (`docker exec wordpress wp user list --allow-root`)
- Website accessible at `https://<login>.42.fr` and should not show a registration page
- Can login with both admin and regular user
- Data should persist after `make down and make up`

## Additional Notes
- SSL certificates are self-signed and generated during NGINX build
- All services should communicate through tyhe `inception` network
- Mariadb network is only accessible within the Docker network
- Wordpress and Mariadb data persists in `/home/<login>/data/` in their respective directories
- The project requires TLSv1.2 or 1.3 protocols only