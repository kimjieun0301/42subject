FROM debian:buster

RUN apt-get update && \
    apt-get install -y mariadb-server

COPY ./tools/setsh.sh /

RUN chmod +x /setsh.sh

ENTRYPOINT ["/setsh.sh"]

CMD ["mysqld"]
