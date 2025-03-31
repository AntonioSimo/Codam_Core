
FROM debian:bookworm

RUN apt-get update && apt-get install -y mariadb-server mariadb-client

#COPY conf/my.cnf /etc/conf/my.cnf
#
#COPY tools/init.sql /docker-entrypoint-initdb.d/
#
#RUN mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

COPY tools/setup.sh /tools/setup.sh

RUN chmod +x /tools/setup.sh

EXPOSE 3306

CMD ["/bin/bash", "/tools/setup.sh"]