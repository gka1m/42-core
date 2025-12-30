FROM debian:bookworm

RUN apt-get update -y && apt-get install -y \
    php-fpm \
    php-mysql \
    curl \
    mariadb-client \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p var/www/html
WORKDIR /var/www/html

COPY wp_setup.sh /wp_setup.sh

RUN chmod +x /wp_setup.sh

EXPOSE 9000

CMD ["/wp_setup.sh"]