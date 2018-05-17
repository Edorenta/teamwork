# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 02:57:04 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/03 00:07:21 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1    	= push_swap
NAME_2    	= checker
SRC_PATH	= srcs/
OBJ_PATH	= objs/
FLAGS		= -Wall -Werror -Wextra
CC			= gcc $(FLAGS)
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRC_SUFFIX	= .c
#SRC_PREFIX	= 
COMMON =	move_utils.c \
			parser_utils.c \
			str_utils.c \
			basics.c \
			bubble_sort.c \
			ext_sort.c \
			move.c \
			parser.c \
			piles_utils.c \
			piles_utils2.c \
			quick_sort.c \
			rebase.c
			#algo.c \
			#checker.c
SRC1_RAW =	$(COMMON) + main.c
SRC2_RAW =	$(COMMON) + checker.c

#SRC_RAW2	= $(addprefix ${SRC_PREFIX},${COMMON})
SRC_FILES	= $(addsuffix $(SRC_SUFFIX),$(COMMON))
SRC_FILES	= $(addsuffix $(SRC_SUFFIX),$(COMMON))

OBJ_FILES	= $(SRC_FILES:.c=.o)
SRC1		= $(addprefix $(SRC_PATH),$(SRC_FILES))
SRC2		= $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ1		= $(addprefix $(OBJ_PATH),$(OBJ_FILES))
OBJ2		= $(addprefix $(OBJ_PATH),$(OBJ_FILES))

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"
#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"

all : $(NAME)

$(NAME) : obj_folder $(OBJ)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"all binaries compiled\t"$(OK)'\n'
	@printf "[$(NAME_P)] running\t$(WHITE)ar rc $@$(WHITE)"
	@ar rc $(NAME) $(OBJ)
	@printf '\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] running\t$(WHITE)ranlib $@$(WHITE)"
	@ranlib	$(NAME)
	@printf '\t\t'$(OK)'\n'
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

obj_folder :
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) -I./include -o $@ -c $<
	@printf '\t'$(OK)

clean :
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJ_PATH)
	@printf '\t\t'$(OK)'\n'

fclean : clean
	@printf "[$(NAME_P)] erasing\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t'$(OK)'\n'

re : fclean all

norm :
	@norminette srcs/ include/

.PHONY: all clean fclean re norm
