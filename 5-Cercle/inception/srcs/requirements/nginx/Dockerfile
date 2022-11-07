FROM    debian:buster

RUN     apt-get update
RUN     apt-get install -y nginx openssl \
        && rm -rf /var/lib/apt/lists/*

RUN     mkdir /etc/nginx/ssl
RUN     openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
        -out /etc/nginx/ssl/armendes.crt \
        -keyout /etc/nginx/ssl/armendes.key \
        -subj "/C=FR/ST=Paris/L=Paris/O=42School/OU=armendes/CN=armendes/"

COPY    ./conf/nginx.conf /etc/nginx/conf.d

RUN     mkdir -p /run/nginx

EXPOSE  443

CMD [ "nginx", "-g", "daemon_off;" ]