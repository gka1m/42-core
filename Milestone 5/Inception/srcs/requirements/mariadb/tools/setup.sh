#!/bin/bash
set -e

echo "🔧 Starting MariaDB setup..."

# Initialize MariaDB data directory if empty
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "📦 Initializing MariaDB data directory..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    echo "🚀 Starting temporary MariaDB for setup..."
    mysqld_safe --skip-networking --socket=/var/run/mysqld/mysqld.sock &
    MYSQL_PID=$!
    
    # Wait for MariaDB to start
    echo "⏳ Waiting for MariaDB to start..."
    for i in {1..30}; do
        if [ -S /var/run/mysqld/mysqld.sock ]; then
            break
        fi
        echo "Waiting for MariaDB socket... ($i/30)"
        sleep 1
    done
    
    # Setup database and users
    echo "📝 Setting up database and users..."
    mysql -S /var/run/mysqld/mysqld.sock -u root <<-EOSQL
        CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
        GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;
EOSQL
    
    echo "✅ Database setup complete."
    
    # Stop temporary instance
    echo "🛑 Stopping temporary MariaDB..."
    kill -TERM $MYSQL_PID
    wait $MYSQL_PID
    sleep 5
else
    echo "📦 Existing database found, skipping initialization."
fi

echo "🚀 Starting MariaDB server..."
exec mysqld --console
