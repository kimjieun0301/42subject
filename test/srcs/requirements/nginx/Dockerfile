FROM debian:buster

RUN apt-get update && \
    apt-get install -y \
    nginx \
    openssl \
    gettext 

COPY ./conf/default /default.template

COPY ./tools/setsh.sh /

RUN chmod +x /setsh.sh

ENTRYPOINT ["/setsh.sh"]

CMD ["nginx", "-g", "daemon off;"]
