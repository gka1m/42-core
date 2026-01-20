#!/bin/bash
set -e

echo "Starting WordPress setup..."

# Read secrets
DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

# Set working directory
cd /var/www/html

# Wait for MariaDB
echo "Waiting for MariaDB..."
count=0
until mysqladmin ping -h"mariadb" --port=3306 -u"${MARIADB_USER}" -p"${DB_PASSWORD}" --silent 2>/dev/null; do
    echo "Attempt $count: MariaDB is unavailable - sleeping"
    sleep 2
    count=$((count + 1))
    if [ $count -gt 30 ]; then
        echo "ERROR: MariaDB failed to become available"
        exit 1
    fi
done
echo "MariaDB is ready!"

# Download and setup WordPress if not present
if [ ! -f "wp-config.php" ]; then
    echo "Fresh installation detected"
    
    # Download WP-CLI if not present
    if [ ! -f "/usr/local/bin/wp" ]; then
        echo "Installing WP-CLI..."
        curl -sS https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp
        chmod +x /usr/local/bin/wp
        echo "WP-CLI installed"
    fi
    
    # Download WordPress core files
    echo "Downloading WordPress... (this may take a moment)"
    wp core download --allow-root --quiet
    echo "WordPress downloaded"
    
    # Create wp-config.php
    echo "Creating wp-config.php..."
    wp config create \
        --allow-root \
        --dbname="${MARIADB_DATABASE}" \
        --dbuser="${MARIADB_USER}" \
        --dbpass="${DB_PASSWORD}" \
        --dbhost="mariadb:3306" \
        --quiet
    echo "wp-config.php created"
    
    # Install WordPress
    echo "Installing WordPress..."
    wp core install \
        --allow-root \
        --url="https://${DOMAIN_NAME}" \
        --title="kagoh's Teatime" \
        --admin_user="${WORDPRESS_ADMIN}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WORDPRESS_ADMIN_EMAIL}" \
        --quiet
    echo "WordPress installed"
    
    # Create second user
    echo "Creating additional user..."
    wp user create \
        --allow-root \
        "${WORDPRESS_USER}" \
        "${WORDPRESS_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role=author \
        --quiet
    echo "Second user created"
    
else
    echo "WordPress already configured, skipping setup"
fi

echo "Changing DB_HOST to current MariaDB port..."
sed -i \
  "s/define( *'DB_HOST'.*/define( 'DB_HOST', 'mariadb:3306' );/" \
  wp-config.php

# Set proper ownership
chown -R www-data:www-data /var/www/html

# Configure php-fpm to listen on TCP port
echo "Configuring PHP-FPM..."
sed -i 's/listen = \/run\/php\/php8.2-fpm.sock/listen = 9000/g' /etc/php/8.2/fpm/pool.d/www.conf

echo "Starting PHP-FPM..."
exec php-fpm8.2 -F