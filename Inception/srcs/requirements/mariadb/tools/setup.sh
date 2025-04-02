#!/bin/sh

# Exit immediately if a command exits with a non-zero status
#set -e

# Create the database directory if it doesn't exist
#if [ ! -d "/var/lib/mysql/mysql" ]; then
#    echo "Initializing database..."
    #mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
#fi

# Start MariaDB in the background
echo "Starting MariaDB..."
service mariadb start

# Wait for MariaDB to be ready
#echo "Waiting for MariaDB to start..."
#until mysqladmin ping --silent; do
#    sleep 1
#done

# Create database and user if they don't exist
echo "Configuring database..."
#mysql -e "CREATE DATABASE IF NOT EXISTS $DB_DATABASE;"
#mysql -e "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';"
#mysql -e "GRANT ALL PRIVILEGES ON $DB_DATABASE.* TO '$DB_USER'@'%';"
#mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';"
#mysql -e "FLUSH PRIVILEGES;"

# Bring MariaDB to foreground so the container doesn't exit
echo "MariaDB is ready!"
#wait
tail -f /dev/null