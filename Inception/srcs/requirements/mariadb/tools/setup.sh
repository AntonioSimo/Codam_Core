# #!/bin/sh

# # Exit immediately if a command exits with a non-zero status
# #set -e

# # Create the database directory if it doesn't exist
# #if [ ! -d "/var/lib/mysql/mysql" ]; then
# #    echo "Initializing database..."
#     #mysql_install_db --user=mysql --datadir=/var/lib/mysql > /dev/null
# #fi

# # Start MariaDB in the background
# SECRETS=/run/secrets
# echo "Starting MariaDB..."
# service mariadb start

# sleep 5


# # Wait for MariaDB to be ready
# #echo "Waiting for MariaDB to start..."
# #until mysqladmin ping --silent; do
# #    sleep 1
# #done

# # Create database and user if they don't exist
# echo "Configuring database..."

# export TEST=$(cat "$SECRETS/credentials")
# export DB_DATABASE=inception
# export PASS=$(cat "$SECRETS/db_root_password")

# echo "This is a test: $TEST"
# echo "db database: $DB_DATABASE"
# echo "db root pass: $PASS"

# echo "Configuring database..."


# # mysql -e "CREATE DATABASE IF NOT EXISTS $DB_DATABASE;"
# # mysql -e "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';"
# # mysql -e "GRANT ALL PRIVILEGES ON $DB_DATABASE.* TO '$DB_USER'@'%';"
# # mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';"
# # mysql -e "FLUSH PRIVILEGES;"

# # Bring MariaDB to foreground so the container doesn't exit
# echo "MariaDB is ready!"
# #wait
# exec mysqld_safe

# exec "$@"



#!/bin/sh

set -e

echo "Starting MariaDB setup..."

# Set variables
SECRETS=/run/secrets
DB_DATABASE=${DB_NAME}
DB_ROOT_PASSWORD=$(cat "$SECRETS/db_root_password")

# Check if DB already initialized
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initializing MariaDB database..."
    mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null

    echo "Starting mysqld to run initial setup..."
    mysqld_safe --skip-networking &
    sleep 5

    echo "Setting up database and users..."
    mysql -u root <<-EOSQL
        CREATE DATABASE IF NOT EXISTS $DB_DATABASE;
        CREATE USER 'user'@'%' IDENTIFIED BY '$(cat "$SECRETS/db_password")';
        GRANT ALL PRIVILEGES ON $DB_DATABASE.* TO 'user'@'%';
        ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD';
        FLUSH PRIVILEGES;
EOSQL

    echo "Database initialized!"
    killall mysqld
    sleep 5
fi

echo "Starting MariaDB server..."
exec mysqld_safe
