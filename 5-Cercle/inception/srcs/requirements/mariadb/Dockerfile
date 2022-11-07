FROM    debian:buster

RUN     apt_get update
RUN     apt-get install -y mariadb-server mariadb_client \
        && rm -rf /var/lib/apt/lists/*

RUN     mkdir -p /var/run/mysqld \
        && chown -R mysql:mysql /var/run/mysqld \
        && chmod 777 /var/run/mysqld

EXPOSE  3306

COPY    ./tools/mariadb.sh /usr/local/bin/
COPY    ./conf/wordpress.sql /usr/local/bin/

ENTRYPOINT [ "/usr/local/bin/mariadb.sh" ]

CMD [ "mysqld", "--bind-address=0.0.0.0" ]