FROM debian:bookworm

RUN apt-get update -y && apt-get install -y mariadb-server 

# Create necessary directories
RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld

# Copy the custom config over
RUN rm -rf /var/lib/mysql/*
# COPY ./50-server.conf /etc/mysql/mariadb.conf.d/50-server.cnf

# Create db and the user on container setup
COPY db_setup.sh /setup.sh
RUN chmod +x /setup.sh

EXPOSE 3306

CMD ["/setup.sh"]