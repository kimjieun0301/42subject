-- Create WordPress database
CREATE DATABASE IF NOT EXISTS wordpress;

-- Create WordPress user and grant privileges
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON wordpress.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;

-- Flush privileges
FLUSH PRIVILEGES;
