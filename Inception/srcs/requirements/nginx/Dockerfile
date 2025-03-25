#We are just going to install the nginx package from the apt package manager and then run nginx 
#in the foreground using the -g command line with the argument daemon off, so that the container 
#wont exit abruptly after we power it on
FROM debian:latest

RUN apt update && apt upgrade && apt install -y nginx

COPY default /etc/nginx/sites-available/.

CMD ["nginx", "-g", "daemon off;"]