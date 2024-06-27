# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 14:51:45 by kagoh             #+#    #+#              #
#    Updated: 2024/06/24 18:30:05 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRC		= ft_printchar.c ft_printhexadec.c ft_printptr.c ft_strchr.c \
		  ft_printf.c ft_printstr.c ft_strlen.c \
		  ft_printnumber.c ft_printunsigned_num.c

OBJ		= $(SRC:.c=.o)

INCLUDES = ft_printf.h

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