# Use an official Debian runtime as a parent image
FROM debian:10

# Set the working directory to /var/www/html
WORKDIR /var/www/html

# Install curl
RUN apt-get update && apt-get install -y curl && rm -rf /var/lib/apt/lists/*

# Download and install WordPress
RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -xzvf latest.tar.gz --strip-components=1 && \
    rm latest.tar.gz && \
    chown -R www-data:www-data /var/www/html

# Expose port
EXPOSE 80

# Specify the command to run on container start
CMD ["apache2-foreground"]



# # Use an official Debian runtime as a parent image
# FROM debian:10

# # Set the working directory to /var/www/html
# WORKDIR /var/www/html

# # Update and install necessary packages
# RUN apt-get update && \
#     apt-get install -y apache2 php php-mysql php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip && \
#     rm -rf /var/lib/apt/lists/*

# # Download and install WordPress
# RUN curl -O https://wordpress.org/latest.tar.gz && \
#     tar -xzvf latest.tar.gz --strip-components=1 && \
#     rm latest.tar.gz && \
#     chown -R www-data:www-data /var/www/html

# # Expose the port the app runs on
# EXPOSE 80

# # Start Apache
# CMD ["apache2-foreground"]
