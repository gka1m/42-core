all: up

up:
	@docker-compose -f ./srcs/docker-compose.yml up -d

down:
	@docker-compose -f ./srcs/docker-compose.yml down

start:
	@docker-compose -f ./srcs/docker-compose.yml start

stop:
	@docker-compose -f ./srcs/docker-compose.yml stop

status:
	@docker ps

logs:
	@docker-compose -f ./srcs/docker-compose.yml logs -f

rebuild:
	@echo "🧹 Cleaning up containers, images, and volumes..."
	@docker-compose -f ./srcs/docker-compose.yml down -v --rmi all
	@echo "🚀 Rebuilding and starting fresh..."
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

re:
	@echo "♻️ Rebuilding containers (keeping cache)..."
	@docker-compose -f ./srcs/docker-compose.yml down
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

clean:
	@echo "🗑️ Removing all containers, images, and volumes..."
	@docker-compose -f ./srcs/docker-compose.yml down -v --rmi all
	@sudo rm -rf /home/kagoh/data/mariadb/*
	@sudo rm -rf /home/kagoh/data/wordpress/*
	@echo "✅ Clean complete!"

fclean: clean
	@docker system prune -af --volumes
	@echo "✅ Full clean complete!"

.PHONY: all up down start stop status logs rebuild re clean fclean