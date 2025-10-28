FROM debian:bookworm

# install the NGINX and OpenSSL
RUN apt-get update && apt-get install -y nginx openssl && apt-get clean

# create SSL directory
RUN mkdir -p /etc/nginx/ssl /var/www/html

# Copy config from config file
COPY config/default.conf /etc/nginx/conf.d/default.conf


# Generate self signed SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-keyout /etc/nginx/ssl/server.key \
-out /etc/nginx/ssl/server.crt \
-subj "/C=FR/ST=Paris/L=Paris/O=42/OU=Inception/CN=${DOMAIN_NAME}"

# Permission settings
RUN chmod 600 /etc/nginx/ssl/server.key /etc/nginx/ssl/server.crt

# expose port 443 as required
EXPOSE 443

# keep nginx in the foreground (no infinite loop)
CMD ["nginx", "-g", "daemon off;"]