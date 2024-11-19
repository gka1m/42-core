# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 15:07:46 by kagoh             #+#    #+#              #
#    Updated: 2024/11/19 14:28:59 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= checks.c initialization.c cleanups.c actions.c stat_monitor.c main.c
		  
OBJ		= $(SRC:.c=.o)

INCLUDES = philo.h

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -fsanitize=thread -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all