FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y \
        php \
        php-cgi \
        php-common \
        php-fpm \
        php-mysql \
        php-gd \
        php-xml \
        php-curl \
        mariadb-client \
        wget \
        curl \
        less \
        unzip \
        git

RUN mkdir -p /var/www/html && \
    chown -R www-data:www-data /var/www/html

RUN mkdir /run/php

RUN sed -i "s/listen.*/listen = 9000/g" /etc/php/7.4/fpm/pool.d/www.conf

COPY tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
