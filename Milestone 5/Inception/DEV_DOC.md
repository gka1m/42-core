# Developer Documentation
This document presents the prerequisites on how to set up and build the project from scratch. The document also provides ways to debug/troubleshoot the project.

---
## Table of Contents

1. [Environment Setup](#environment-setup)
2. [Project Structure](#project-structure)
3. [Building and Launching](#building-and-launching)
4. [Container Management](#container-management)
5. [Volume Management](#volume-management)
6. [Data Persistence](#data-persistence)
7. [Debugging and Troubleshooting](#debugging-and-troubleshooting)
8. [Development Workflow](#development-workflow)

## Environment Setup

### Required Software
The following software are needed in order to get started:
1. Docker Engine
2. Docker Compose
3. GNU Make
4. Linux-based environment (Penultimate stable version of Debian at time of project commencement)

### User Permissions
The user must have permission to run Docker commands.

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
mkdir -p /home/login/data/wordpress
mkdir -p /home/login/data/mariadb
```

Remember to set the required permissions for the directories.
```
chmod +x <path to file>
```

## Project Structure
```
inception/
├── Makefile                         
├── srcs/
│   ├── docker-compose.yml         
│   ├── .env                          
│   ├── secrets/                      
│   │   ├── db_password.txt
│   │   ├── wp_admin_password.txt
│   │   └── wp_user_password.txt
│   └── requirements/
│       ├── nginx/
│       │   ├── Dockerfile
│       │   ├── default.conf      
│       ├── wordpress/
│       │   ├── Dockerfile
│       │   └── wp_setup.sh           
│       └── mariadb/
│           ├── Dockerfile
│           └── db_setup.sh           
└── README.md
```
