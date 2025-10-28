FROM debian:bookworm

# Install prerequisites and PHP 7.4 from Sury repository
RUN apt-get update && apt-get install -y \
    lsb-release ca-certificates apt-transport-https software-properties-common curl gnupg2 \
    && curl -fsSL https://packages.sury.org/php/apt.gpg | apt-key add - \
    && echo "deb https://packages.sury.org/php/ $(lsb_release -sc) main" > /etc/apt/sources.list.d/sury-php.list \
    && apt-get update && apt-get install -y \
        php7.4-fpm php7.4-mysql mariadb-client \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

# Configure PHP-FPM to listen on port 9000 and run in foreground
RUN sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 9000|g' /etc/php/7.4/fpm/pool.d/www.conf \
    && sed -i 's|;daemonize = yes|daemonize = no|g' /etc/php/7.4/fpm/php-fpm.conf

# Copy the setup script
COPY tools/setup.sh /usr/local/bin/setup.sh
# COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/setup.sh

# pre create config file manually
# Ensure wp-config.php exists and is writable by PHP
RUN touch /var/www/html/wp-config.php \
    && chown www-data:www-data /var/www/html/wp-config.php \
    && chmod 660 /var/www/html/wp-config.php

# COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
# RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 9000

# Run the setup script when the container starts
# ENTRYPOINT ["/usr/local/bin/setup.sh"]
CMD ["/usr/local/bin/setup.sh"]
