# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 17:13:01 by kagoh             #+#    #+#              #
#    Updated: 2024/07/05 17:13:01 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_printchar.c ft_printf.c ft_printhexadec.c ft_printnumber.c \
		  ft_printptr.c ft_printstr.c ft_printunsigned_num.c ft_strchr.c \
		  ft_strlen.c swap_ops.c push_ops.c push_swap.c

OBJ		= $(SRC:.c=.o)

INCLUDES = push_swap.h ft_printf.h

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

all: $(NAME)

.PHONY: clean fclean re all