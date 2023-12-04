#!/bin/bash

# Wait for the MariaDB service to be ready
until mysqladmin ping -h"$DB_HOST" --silent; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
done

# Create WordPress database
mysql -u"$DB_USER" -p"$DB_PASSWORD" -h"$DB_HOST" -e "CREATE DATABASE IF NOT EXISTS $DB_NAME;"

# Create WordPress user and grant privileges
mysql -u"$DB_USER" -p"$DB_PASSWORD" -h"$DB_HOST" -e "CREATE USER IF NOT EXISTS '$WP_DB_USER'@'%' IDENTIFIED BY '$WP_DB_PASSWORD';"
mysql -u"$DB_USER" -p"$DB_PASSWORD" -h"$DB_HOST" -e "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$WP_DB_USER'@'%' WITH GRANT OPTION;"

# Flush privileges
mysql -u"$DB_USER" -p"$DB_PASSWORD" -h"$DB_HOST" -e "FLUSH PRIVILEGES;"

# Initialize WordPress configuration
cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php
sed -i "s/database_name_here/$DB_NAME/" /var/www/html/wp-config.php
sed -i "s/username_here/$WP_DB_USER/" /var/www/html/wp-config.php
sed -i "s/password_here/$WP_DB_PASSWORD/" /var/www/html/wp-config.php
sed -i "s/localhost/$DB_HOST/" /var/www/html/wp-config.php
sed -i "s/utf8/utf8mb4/" /var/www/html/wp-config.php

# Set authentication unique keys and salts
curl -s https://api.wordpress.org/secret-key/1.1/salt/ >> /var/www/html/wp-config.php

# Change ownership of WordPress files to www-data
chown -R www-data:www-data /var/www/html

# Remove the script to prevent it from being executed again
rm /var/www/html/init_wordpress.sh
