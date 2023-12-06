#!/bin/bash

set -e

cat /default.template \
	| envsubst '443 $DOMAIN_NAME /etc/ssl/certs/nginx.crt /etc/ssl/private/nginx_pkey.pem $NGINX_WP_HOST 9000' \
	> /etc/nginx/sites-available/default

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx_pkey.pem -out /etc/ssl/certs/nginx.crt \
	-subj "/C=KR/L=Seoul/O=42seoul/CN=$DOMAIN_NAME"

exec "$@"
