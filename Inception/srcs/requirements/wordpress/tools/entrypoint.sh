#!/bin/bash
set -e

until mysqladmin ping -h"mariadb" --silent; do
    echo "⌛ Waiting for MariaDB..."
    sleep 2
done

if [ ! -f /var/www/html/wp-config.php ]; then
    curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

    echo "🔧 Downloading stable WordPress..."
    wp --allow-root core download --path=/var/www/html

    echo "⚙️ Setting up WordPress config..."
    wp  config create --path=/var/www/html --dbname="$MYSQL_DATABASE" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --dbhost="$DB_HOST" --skip-check --allow-root

    echo "🚀 Installing WordPress..."
    echo "User: $WORDPRESS_ADMIN_USER"
    echo "Pass: $WORDPRESS_ADMIN_PASSWORD"
    wp core install --path=/var/www/html --url=asimone.42.fr --title="$WORDPRESS_TITLE" --admin_user="$WORDPRESS_ADMIN_USER" --admin_password="$WORDPRESS_ADMIN_PASSWORD" --admin_email="$WORDPRESS_EMAIL" --allow-root

	wp --allow-root user create "$WORDPRESS_DB_USER" asimone@student.codam.nl --path="/var/www/html" --user_pass="$WORDPRESS_DB_PASSWORD"
fi

echo "✅ WordPress is ready! Starting PHP-FPM..."

exec /usr/sbin/php-fpm7.4 -F