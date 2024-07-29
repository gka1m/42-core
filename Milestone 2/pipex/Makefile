# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kagoh <kagoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 22:27:06 by kagoh             #+#    #+#              #
#    Updated: 2024/07/29 15:57:35 by kagoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

PRINTF_DIR = ft_printf

SRC		= $(PRINTF_DIR)/ft_printchar.c $(PRINTF_DIR)/ft_printf.c $(PRINTF_DIR)/ft_printhexadec.c \
		  $(PRINTF_DIR)/ft_printnumber.c $(PRINTF_DIR)/ft_printptr.c $(PRINTF_DIR)/ft_printstr.c \
		  $(PRINTF_DIR)/ft_printunsigned_num.c $(PRINTF_DIR)/ft_strchr.c \
		  $(PRINTF_DIR)/ft_strlen.c ft_split.c ft_strdup.c ft_strlcat.c ft_strncmp.c \
		  ft_strcpy.c utils.c utils2.c pipex.c

OBJ		= $(SRC:.c=.o)

INCLUDES = pipex.h $(PRINTF_DIR)/ft_printf.h

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