#!/bin/bash

set -e

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/ssl/private/nginx_pkey.pem -out /etc/ssl/certs/nginx.crt \
	-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/CN=jkim3.42.fr"

exec "$@"
