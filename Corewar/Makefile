# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 19:21:52 by pde-rent          #+#    #+#              #
#    Updated: 2018/06/13 19:30:54 by jjourne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1    	= asm
NAME_2    	= corewar
SRC_PATH	= srcs/
OBJ_PATH	= objs/
FLAGS		= -Wall -Werror -Wextra -g -fsanitize=address
CC			= gcc $(FLAGS)
NAME_P		= $(shell echo $(NAME_1) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRC_SUFFIX	= .c

COMMON =	op

# Common Files
COMMON_FILES =	$(addsuffix $(SRC_SUFFIX),$(COMMON))
SRC1_FILES = $(COMMON_FILES)
SRC2_FILES = $(COMMON_FILES)

SRC2_FILES += corewar.c
SRC1_FILES += asm.c


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
	"$(NAME_1) compiled\t"$(OK)'\n'
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

libft :
	@make -C ./printf

clean :
	@printf "[$(NAME_P)] removing\t\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJ_PATH)
	@make clean -C ./printf
	@printf '\t\t'$(OK)'\n'

fclean : clean
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(NAME_1)$(WHITE)"
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)
	@make fclean ./printf
	@printf '\t\t'$(OK)'\n'

re : fclean all

norm :
	@norminette srcs/ include/

.PHONY: all clean fclean re norm
