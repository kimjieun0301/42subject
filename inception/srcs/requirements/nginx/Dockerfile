# Use Debian 10 (Buster)
FROM debian:10

# Install necessary packages
RUN apt-get update && \
    apt-get install -y nginx openssl && \
    rm -rf /var/lib/apt/lists/*

# Copy NGINX configuration file
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# Create a self-signed SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/nginx.key -out /etc/nginx/nginx.crt -subj "/C=US/ST=State/L=City/O=Organization/CN=localhost"

# Expose port 443 for HTTPS
EXPOSE 443

# Command to start NGINX with TLSv1.2 or TLSv1.3 only
CMD ["nginx", "-g", "daemon off;"]