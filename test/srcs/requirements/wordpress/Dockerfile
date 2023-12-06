FROM debian:buster

WORKDIR /var/www/html

RUN apt-get update && \
    apt-get install -y \
    php7.3 \
    php7.3-fpm \
    php7.3-mysql \
    default-mysql-client \
    curl


RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/setsh.sh /

RUN chmod +x /setsh.sh

ENTRYPOINT ["/setsh.sh"]

CMD ["php-fpm7.3", "--nodaemonize"]
