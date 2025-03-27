#We are just going to install the nginx package from the apt package manager and then run nginx 
#in the foreground using the -g command line with the argument daemon off, so that the container 
#wont exit abruptly after we power it on

FROM debian:latest
#install Nginx
RUN apt-get update -y
RUN apt-get install -y nginx openssl
#copy configuration file
COPY conf/default.conf /etc/nginx/conf/default.conf
#expose port 443
EXPOSE 443
#run Nginix
CMD ["nginx", "-g", "daemon off;"]