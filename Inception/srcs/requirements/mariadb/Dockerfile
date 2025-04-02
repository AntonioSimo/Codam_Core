# Set the base image to Debian 12 (Bookworm)
FROM debian:bookworm
# Update package lists and install MariaDB Server
RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*

#COPY tools/init.sql /docker-entrypoint-initdb.d/
# Create necessary directories (to store the datas and to store the logs)
#RUN mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

COPY conf/my.cnf /etc/mysql/my.cnf
# Copy the entrypoint script into the container
COPY tools/setup.sh /setup.sh
# Give execution permissions
RUN chmod +x /setup.sh

EXPOSE 3306
# Define the setup script
CMD ["/setup.sh"] 
#, "mysqld_safe"]