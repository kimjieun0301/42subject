# Use Debian 10 (Buster)
FROM debian:10

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Install necessary packages
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# Expose the port the app runs on
EXPOSE 3306

# Start MariaDB service
CMD ["mysqld", "--user=mysql"]
