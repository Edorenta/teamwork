# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 02:57:04 by pde-rent          #+#    #+#              #
#    Updated: 2018/05/23 18:01:22 by fmadura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1    	= push_swap
NAME_2    	= checker
SRC_PATH	= srcs/
OBJ_PATH	= objs/
FLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
CC			= gcc $(FLAGS)
NAME_P		= $(shell echo $(NAME_1) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRC_SUFFIX	= .c
#SRC_PREFIX	= 
COMMON =	move_utils \
			env_utils \
			parser_utils \
			str_utils \
			basics \
			bubble_sort \
			move \
			parser \
			piles_utils \
			piles_utils2 \
			piles_utils3 \
			quick_utils \
			quick_sort \
			ladder_sort \
			ladder_utils \
			interpret \
			optimizer

COMMON_FILES =	$(addsuffix $(SRC_SUFFIX),$(COMMON))
SRC1_FILES = $(COMMON_FILES)
SRC1_FILES += main.c
SRC2_FILES = $(COMMON_FILES)
SRC2_FILES += checker.c

#SRC_RAW2	= $(addprefix ${SRC_PREFIX},${COMMON})

OBJ1_FILES	= $(SRC1_FILES:.c=.o)
OBJ2_FILES	= $(SRC2_FILES:.c=.o)
SRC1		= $(addprefix $(SRC_PATH),$(SRC1_FILES))
SRC2		= $(addprefix $(SRC_PATH),$(SRC2_FILES))
OBJ1		= $(addprefix $(OBJ_PATH),$(OBJ1_FILES))
OBJ2		= $(addprefix $(OBJ_PATH),$(OBJ2_FILES))

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

all : $(NAME_1) $(NAME_2)

$(NAME_1) : $(OBJ1)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"push_swap compiled\t"$(OK)'\n'
	@ $(CC) -I./includes $(OBJ1) -o $@
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

$(NAME_2) : $(OBJ2)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"checker compiled\t"$(OK)'\n'
	@ $(CC) -I./includes $(OBJ2) -o $@
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

$(OBJ1) : | $(OBJ_PATH)
$(OBJ2) : | $(OBJ_PATH)

$(OBJ_PATH) : 
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) -I./includes -o $@ -c $<
	@printf '\t'$(OK)

clean :
	@printf "[$(NAME_P)] removing\t\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJ_PATH)
	@printf '\t\t'$(OK)'\n'

fclean : clean
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(NAME_1)$(WHITE)"
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)
	@printf '\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] erasing\t\t$(PINK)visualizer binaries$(WHITE)"
	@rm -f _visualizer/c/list_jsonifier.exe
	@rm -f _visualizer/c/rnd_int.exe
	@printf '\t'$(OK)'\n'
	@printf "[$(NAME_P)] erasing\t\t$(PINK)visualizer cache$(WHITE)"
	@rm -f _visualizer/html/tmp.html
	@rm -f _visualizer/html/index.html
	@rm -f _visualizer/commands.json
	@rm -f _visualizer/commands.txt
	@rm -f _visualizer/unsorted_list.json
	@rm -f _visualizer/unsorted_list.txt
	@printf '\t'$(OK)'\n'

re : fclean all

norm :
	@norminette srcs/ include/

.PHONY: all clean fclean re norm
