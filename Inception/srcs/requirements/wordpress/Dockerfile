# #we begin by installing the service from the apt package manager and run the php-fpm 
# #service in the foreground using the command line -F ( Force to run in background and 
# #ignore daemonize option from configuration file. )
# FROM debian:latest

# RUN apt update && apt upgrade && apt install -y php-fpm

# COPY www.conf /etc/php/8.2/fpm/pool.d/.

# EXPOSE 9000

# CMD ["php-fpm8.2", "-F"]

# Set the base image to Debian 12 (Bookworm)
FROM debian:bookworm

# Install PHP and required extensions
RUN apt update && \
    apt install -y php8.2-fpm php8.2-mysql php8.2-curl php8.2-gd php8.2-mbstring php8.2-xml php8.2-zip wget unzip && \
    rm -rf /var/lib/apt/lists/*

# Create WordPress directory and set correct permissions
RUN mkdir -p /var/www/html && \
    chown -R www-data:www-data /var/www/html

# Download and extract WordPress
WORKDIR /var/www/html
RUN wget https://wordpress.org/latest.tar.gz && \
    tar -xvzf latest.tar.gz --strip-components=1 && \
    rm latest.tar.gz

# Copy custom PHP-FPM config
COPY www.conf /etc/php/8.2/fpm/pool.d/.

# Expose port 9000 for PHP-FPM
EXPOSE 9000

# Start PHP-FPM in foreground
CMD ["php-fpm8.2", "-F"]