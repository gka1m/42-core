#!/bin/bash
set -e

WP_PATH="/var/www/html"

echo "🔧 Starting WordPress setup..."

# --- 1. Wait for database to be ready ---
echo "⏳ Waiting for database to be ready..."
while ! mysqladmin ping -h"${WORDPRESS_DB_HOST}" -u"${WORDPRESS_DB_USER}" -p"${WORDPRESS_DB_PASSWORD}" --silent; do
    echo "Waiting for database connection..."
    sleep 5
done

# --- 2. Install WordPress if not present ---
if [ ! -f "${WP_PATH}/wp-settings.php" ]; then
    echo "⚙️ Installing WordPress into ${WP_PATH}..."
    # Clean directory first
    rm -rf ${WP_PATH}/*
    
    cd /tmp
    curl -O https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    rm latest.tar.gz
    cp -r wordpress/* "${WP_PATH}/"
    rm -rf wordpress
    echo "✅ WordPress files copied successfully."
else
    echo "📦 WordPress already installed."
fi

# --- 3. Fix permissions ---
echo "⚙️ Setting permissions..."
chown -R www-data:www-data "${WP_PATH}"
chmod -R 755 "${WP_PATH}"
find "${WP_PATH}" -type f -exec chmod 644 {} \;

# --- 4. Create or verify wp-config.php ---
CONFIG="${WP_PATH}/wp-config.php"
echo "⚙️ Configuring wp-config.php..."

# Create database if it doesn't exist
echo "📦 Ensuring database exists..."
mysql -h"${WORDPRESS_DB_HOST}" -u"${WORDPRESS_DB_USER}" -p"${WORDPRESS_DB_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS ${WORDPRESS_DB_NAME};"

cat > "$CONFIG" <<EOL
<?php
define('DB_NAME', '${WORDPRESS_DB_NAME}');
define('DB_USER', '${WORDPRESS_DB_USER}');
define('DB_PASSWORD', '${WORDPRESS_DB_PASSWORD}');
define('DB_HOST', '${WORDPRESS_DB_HOST}');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

// Debug settings
define('WP_DEBUG', true);
define('WP_DEBUG_LOG', true);
define('WP_DEBUG_DISPLAY', false);

\$table_prefix = 'wp_';

if ( ! defined('ABSPATH') ) {
    define('ABSPATH', __DIR__ . '/');
}

require_once ABSPATH . 'wp-settings.php';
EOL

chown www-data:www-data "$CONFIG"
chmod 660 "$CONFIG"
echo "✅ wp-config.php created successfully."

# --- 5. Verify critical files exist ---
echo "🔍 Verifying WordPress installation..."
if [ -f "${WP_PATH}/wp-settings.php" ] && [ -f "${WP_PATH}/wp-includes/functions.php" ]; then
    echo "✅ WordPress installation verified."
else
    echo "❌ WordPress installation incomplete!"
    exit 1
fi

echo "🚀 Starting PHP-FPM..."
exec php-fpm7.4 -F