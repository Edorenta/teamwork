# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 18:34:12 by jyildiz-          #+#    #+#              #
#    Updated: 2018/05/15 11:26:18 by fmadura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
CFLAGS_DBG = -g -fsanitize=address

OBJ_PATH = ./objs/
SRC_PATH = ./srcs/
INC_PATH = ./includes

NAME1 = push_swap
NAME2 = checker

SRC1_NAME = checker.c
SRC2_NAME = push_swap.c

SRC_NAME = algo.c \
		   checker.c \
	 	   main.c \
   		   move_utils.c \
		   parser_utils.c \
		   str_utils.c \
		   bubble_sort.c \
		   ext_sort.c \
		   move.c \
		   parser.c \
		   piles_utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))

.PHONY : all clean fclean re

all : $(OBJ) $(NAME1) $(NAME2)

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@ mkdir ./objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME1) :
	@ $(CC) $(CFLAGS) $(INC) -c $(SRC1) $(OBJ)

$(NAME2) :
	@ $(CC) $(CFLAGS) $(INC) -c $(SRC2) $(OBJ)

clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf $(NAME1) $(NAME2)

dbg :
	@ $(CC) $(CFLAGS) $(CFLAGS_DBG) ../tests/test.c

re : fclean all
