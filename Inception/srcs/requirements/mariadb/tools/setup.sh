#!/bin/sh

set -e

echo "⚙️ Starting MariaDB setup..."

if [ -d "/var/lib/mysql/$DB_HOST" ]; then 
    echo "📂 Database already exists"
else
{
    echo "✅ Initializing MariaDB database..."
    mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql

    echo "🚀 Starting mysqld to run initial setup..."
    mysqld_safe --skip-networking &
    
    until mysqladmin ping --silent; do
        echo "⏳ Waiting for mysqld to be ready..."
        sleep 1
    done

    echo "⚙️  Setting up database and users..."
    mysql -e "CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;"
    mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
    mysql -e "GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';"
    mysql -e "FLUSH PRIVILEGES;"

    echo "✅ Database initialized!"
    mysqladmin --user=root shutdown
    sleep 5
}
fi

echo "✅ Starting MariaDB server..."
exec mysqld_safe