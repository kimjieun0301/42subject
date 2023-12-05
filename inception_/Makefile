all		:	
			@mkdir -p /home/jkim3/data/mariadb
			@mkdir -p /home/jkim3/data/wordpress
			docker-compose -f ./srcs/docker-compose.yml up -d --build

clean	:
			docker-compose -f ./srcs/docker-compose.yml down

fclean	:
			docker-compose -f ./srcs/docker-compose.yml down --rmi all
			docker volume rm -f mariadb wordpress
			@rm -rf /home/jkim3/data

re		:	fclean all

.PHONY	:	all clean fclean re up down restart
