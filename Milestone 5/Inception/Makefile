MAKEFLAGS += --no-print-directory

all: up

up: copy-secrets
	mkdir -p /home/kagoh/data/mariadb
	mkdir -p /home/kagoh/data/wordpress
	@docker-compose -f ./srcs/docker-compose.yml up --build -d
	@$(MAKE) health-check

copy-secrets:
	@echo "Copying secrets..."
	@mkdir -p ./secrets
	@cp /home/kagoh/secrets/db_password.txt ./secrets/db_password.txt
	@cp /home/kagoh/secrets/wp_admin_password.txt ./secrets/wp_admin_password.txt
	@cp /home/kagoh/secrets/wp_user_password.txt ./secrets/wp_user_password.txt
	@chmod 600 ./secrets/*.txt
	@echo "Secrets copied successfully"

down:
	@docker-compose -f ./srcs/docker-compose.yml down

clean:
	@docker-compose -f ./srcs/docker-compose.yml down -v --remove-orphans

rebuild:
	@docker-compose -f ./srcs/docker-compose.yml down -v
	@sudo rm -rf /home/kagoh/data/mariadb/*
	@sudo rm -rf /home/kagoh/data/wordpress/*
	@docker-compose -f ./srcs/docker-compose.yml up --build -d
	@$(MAKE) health-check

health-check:
	@echo "Checking container health..."
	@$(MAKE) wait SERVICE=mariadb LABEL=MariaDB
	@echo ""
	@echo ""
	@$(MAKE) wait SERVICE=wordpress LABEL=WordPress
	@echo ""
	@echo ""
	@$(MAKE) wait SERVICE=nginx LABEL=NGINX
	@echo ""
	@echo ""
	@echo "All services are healthy and ready!"

wait:
	@printf "%-12s " "$(LABEL):"
	@while [ "$$(docker inspect --format='{{.State.Health.Status}}' $(SERVICE) 2>/dev/null)" != "healthy" ]; do \
		sleep 1; \
	done
	@width=$$(tput cols); \
	label_len=13; \
	status_len=5; \
	dots=$$((width - label_len - status_len)); \
	if [ $$dots -gt 0 ]; then printf "%$${dots}s" | tr ' ' '.'; fi; \
	printf " \033[0;32m[up]\033[0m\n"

restart:
	@docker-compose -f ./srcs/docker-compose.yml down
	@docker-compose -f ./srcs/docker-compose.yml up --build -d
	@$(MAKE) health-check

status:
	@docker ps

fclean: clean
	@sudo rm -rf /home/kagoh/data/mariadb
	@sudo rm -rf /home/kagoh/data/wordpress
	@docker system prune -a -f
	@echo "Full clean complete!"

.PHONY: all up down clean re rebuild status fclean copy-secrets health-check wait