# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 17:13:01 by kagoh             #+#    #+#              #
#    Updated: 2024/10/14 14:16:19 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

PRINTF_DIR = ft_printf

SRC		= $(PRINTF_DIR)/ft_printchar.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printhexadec.c \
		  $(PRINTF_DIR)/ft_printnumber.c $(PRINTF_DIR)/ft_printptr.c $(PRINTF_DIR)/ft_printstr.c \
		  $(PRINTF_DIR)/ft_printunsigned_num.c $(PRINTF_DIR)/ft_strchr.c \
		  $(PRINTF_DIR)/ft_strlen.c push.c rev_rot.c rotate.c swap.c \
		  ft_atoi.c checks.c initialization.c sorting.c push_swap.c \
		  ft_split.c

OBJ		= $(SRC:.c=.o)

INCLUDES = push_swap.h $(PRINTF_DIR)/ft_printf.h

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all