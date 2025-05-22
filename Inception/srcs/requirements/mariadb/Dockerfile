# Set the base image to Debian 12 (Bookworm)
FROM debian:bullseye
# Update package lists and install MariaDB Server
RUN apt-get -y update && apt-get -y upgrade && apt-get install -y mariadb-server && apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysql; chown -R mysql:root /var/run/mysql

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
# Copy the entrypoint script into the container
COPY tools/setup.sh /setup.sh
# Give execution permissions
RUN chmod +x /setup.sh

EXPOSE 3306
# Define the setup script
ENTRYPOINT ["sh", "/setup.sh"]