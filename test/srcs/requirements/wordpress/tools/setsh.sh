#!/bin/bash

set -e

sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g" /etc/php/7.3/fpm/pool.d/www.conf
mkdir -p /run/php

if [ ! -f /var/www/html/wp-config.php ]; then
wp core download --path=/var/www/html --allow-root
wp core config --path=/var/www/html --dbname=$WP_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=$WP_DB_HOST --allow-root
wp core install --path=/var/www/html --url=https://$DOMAIN_NAME --title=inception \
	--admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASS --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
wp user create $WP_USER $WP_USER_EMAIL --role=subscriber --user_pass=$WP_USER_PASS --allow-root
fi

exec "$@"
