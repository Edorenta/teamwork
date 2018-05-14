# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 18:34:12 by jyildiz-          #+#    #+#              #
#    Updated: 2018/05/14 14:51:12 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -O2 -g -fsanitize=address
NAME1 = push_swap
NAME2 = checker
SOURCE1 = checker.c
SOURCE2 = push_swap.c
SOURCES = check_error.c \
		  move.c \
		  test.c \
		  parsing_utils.c \
		  stock_table.c

OBJ = $(SOURCES:.c=.o)

all : $(NAME1) $(NAME2)

$(NAME1) :
	@ $(CC) $(CFLAGS) -c $(SOURCE1) $(SOURCES)

$(NAME2) :
	@ $(CC) $(CFLAGS) -c $(SOURCE2) $(SOURCES)

clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf $(NAME1) $(NAME2)

dbg :
	@ gcc test.c

re : fclean all
