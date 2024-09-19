# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/07 14:46:59 by kagoh             #+#    #+#              #
#    Updated: 2024/09/18 18:07:47 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= map_test

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g
# MINILIBX_FLAGS	= -lmlx -lXext -lX11

PRINTF_DIR	= ft_printf

SRC		= $(PRINTF_DIR)/ft_printchar.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printhexadec.c \
		  $(PRINTF_DIR)/ft_printnumber.c $(PRINTF_DIR)/ft_printptr.c $(PRINTF_DIR)/ft_printstr.c \
		  $(PRINTF_DIR)/ft_printunsigned_num.c $(PRINTF_DIR)/ft_strchr.c \
		  $(PRINTF_DIR)/ft_strlen.c check1.c check2.c check3.c test.c ft_split.c ft_strncmp.c

OBJ		= $(SRC:.c=.o)

INCLUDES = so_long.h $(PRINTF_DIR)/ft_printf.h

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all