FROM debian:buster

RUN apt-get update && \
    apt-get install -y \
    php7.3 \
    php7.3-fpm \
    php7.3-mysql \
    default-mysql-client \
    curl

WORKDIR /var/www/html

COPY ./tools/entrypoint.sh /

RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]

CMD ["php-fpm7.3", "--nodaemonize"]
