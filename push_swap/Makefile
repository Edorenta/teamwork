# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 18:34:12 by jyildiz-          #+#    #+#              #
#    Updated: 2018/05/12 06:08:57 by jyildiz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME1 = push_swap
NAME2 = checker
SOURCE1 = checker.c
SOURCE2 = push_swap.c
SOURCES = check_error.c is_sort.c move.c stock_table.c parsing_utils.c
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

re : fclean all
