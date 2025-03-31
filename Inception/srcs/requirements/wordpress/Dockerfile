#we begin by installing the service from the apt package manager and run the php-fpm 
#service in the foreground using the command line -F ( Force to run in background and 
#ignore daemonize option from configuration file. )
FROM debian:latest

RUN apt update && apt upgrade && apt install -y php-fpm

COPY www.conf /etc/php/8.2/fpm/pool.d/.

EXPOSE 9000

CMD ["php-fpm8.2", "-F"]