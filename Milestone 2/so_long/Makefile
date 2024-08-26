# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 14:46:59 by kagoh             #+#    #+#              #
#    Updated: 2024/08/26 12:41:01 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				= clang

CFLAGS			= -Wall -Wextra -Werror
MINILIBX_FLAGS	= -lmlx -lXext -lX11

SRC		= 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all