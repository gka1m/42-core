all: up

up:  
	mkdir -p /home/kagoh/data/mariadb
	mkdir -p /home/kagoh/data/wordpress
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

down:
	@docker-compose -f ./srcs/docker-compose.yml down

clean:
	@docker-compose -f ./srcs/docker-compose.yml down -v --remove-orphans

re: clean up

rebuild:
	@docker-compose -f ./srcs/docker-compose.yml down -v
	@sudo rm -rf /home/kagoh/data/mariadb/*
	@sudo rm -rf /home/kagoh/data/wordpress/*
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

status:
	@docker ps

fclean: clean
	@sudo rm -rf /home/kagoh/data/mariadb
	@sudo rm -rf /home/kagoh/data/wordpress
	@docker system prune -a -f
	@echo "Full clean complete!"

.PHONY: all up down clean re status fclean
