FROM debian:bullseye

RUN apt-get update -y
RUN apt-get install -y nginx openssl

RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
  -out /etc/ssl/certs/asimone.42.fr.crt \
  -keyout /etc/ssl/certs/asimone.42.fr.key \
  -subj "/C=NL/ST=North-Holland/L=Amsterdam/O=Codam/OU=asimone/CN=asimone.42.fr"

COPY conf/default.conf /etc/nginx/conf.d/default.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
