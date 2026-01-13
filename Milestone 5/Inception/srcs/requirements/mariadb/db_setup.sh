#!/bin/bash
set -e

echo "Starting MariaDB setup..."

DB_PASSWORD=$(cat /run/secrets/db_password)


echo "Checking /var/lib/mysql contents..."
ls -la /var/lib/mysql/ || echo "Directory is empty or doesn't exist"

# Initialize database if empty
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "FRESH INSTALLATION"
    echo "Initializing database..."
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    echo "Starting temporary MariaDB..."
    mysqld --user=mysql --skip-networking &
    pid="$!"

    # Wait for MariaDB
    until mysqladmin ping --silent; do
        sleep 1
    done

    echo "Creating database and user..."
    mysql <<EOF
        DELETE FROM mysql.user WHERE user='';
        CREATE DATABASE IF NOT EXISTS \`${MARIADB_DATABASE}\`;
        CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
        GRANT ALL PRIVILEGES ON \`${MARIADB_DATABASE}\`.* TO '${MARIADB_USER}'@'%';
        FLUSH PRIVILEGES;
EOF
    echo "Setup complete"

    echo "Stopping temporary MariaDB..."
    mysqladmin shutdown
    wait "$pid"
fi

echo "Starting MariaDB server..."
exec mysqld --user=mysql --bind-address=0.0.0.0 --port=3306
