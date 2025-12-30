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
1. Docker and Docker Compose
2. GNU Make
3. Linux-based environment (Penultimate stable version of Debian)

The user must have permission to run Docker commands.

### Files
The project needs to have a .env file where variables will be defined, and a secrets folder where sensitive information (e.g. passwords) will be stored.

Example variables in .env file:
```
MARIADB_DATABASE = wordpress
DOMAIN_NAME = login.42.fr
```

### Data Directories
Directories for the data should exist on the host system. 