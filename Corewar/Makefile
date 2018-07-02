# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 19:21:52 by pde-rent          #+#    #+#              #
#    Updated: 2018/07/02 21:00:28 by fmadura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1    	= asm
NAME_2    	= corewar

SRC_PATH1	= srcs/asm/
SRC_PATH2	= srcs/vm/

OBJ_PATH1	= objs/asm/
OBJ_PATH2	= objs/vm/

FLAGS		= -Wall -Werror -Wextra
CC			= gcc $(FLAGS)
NAME_P		= $(shell echo $(NAME_1) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
# SRC_SUFFIX	= .c

# COMMON =	op

# Common Files
# COMMON_FILES =	$(addsuffix $(SRC_SUFFIX),$(COMMON))
# SRC1_FILES = $(COMMON_FILES)
# SRC2_FILES = $(COMMON_FILES)

# SRC2_FILES += 	vm/corewar.c vm/check_arg.c vm/parse_player.c
SRC2_FILES = 	corewar.c check_arg.c parse_player.c \
				player.c parse_op.c check_ocp.c \
				show.c process.c get_arg.c \
				core.c op.c tools.c \
				flib.c action_proc.c client.c \
				opcode/live.c \
				opcode/ld.c \
				opcode/st.c \
				opcode/add.c \
				opcode/sub.c \
				opcode/and.c \
				opcode/or.c \
				opcode/xor.c \
				opcode/zjmp.c \
				opcode/ldi.c \
				opcode/sti.c \
				opcode/lld.c \
				opcode/lldi.c \
				opcode/lfork.c \
				opcode/aff.c \
				opcode/fork.c
# SRC1_FILES +=	asm/asm.c
SRC1_FILES =	asm.c \
      			op.c \
      			main.c \
      			parser.c \
      			lexer.c \
      			lexer_basic.c \
      			lexer_ins.c \
      			struct_iter.c \
      			struct_lab.c \
      			struct_ops.c \
      			struct_token.c \
      			check.c \
      			utils.c \
      			utils_ops.c \
      			utils_lab.c \
      			utils_iter.c \
     			write.c \
				params.c

OBJ1_FILES	= $(SRC1_FILES:.c=.o)
OBJ2_FILES	= $(SRC2_FILES:.c=.o)
OBJ1		= $(addprefix $(OBJ_PATH1),$(OBJ1_FILES))
OBJ2		= $(addprefix $(OBJ_PATH2),$(OBJ2_FILES))
SRC1		= $(addprefix $(SRC_PATH1),$(SRC1_FILES))
SRC2		= $(addprefix $(SRC_PATH2),$(SRC2_FILES))

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
	@ $(CC) -I./includes -I./libft/includes $(OBJ1) -o $@
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

$(NAME_2) : $(OBJ2)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"checker compiled\t"$(OK)'\n'
	@ $(CC) -I./includes -I./libft/includes $(OBJ2) -o $@
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

$(OBJ1) : | $(OBJ_PATH1)
$(OBJ2) : | $(OBJ_PATH2)

$(OBJ_PATH1) :
	@mkdir -p $(OBJ_PATH1)

$(OBJ_PATH2) :
	@mkdir -p $(OBJ_PATH2)

$(OBJ_PATH1)%.o: $(SRC_PATH1)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) -I./includes -I./libft/includes -o $@ -c $<
	@printf '\t'$(OK)

$(OBJ_PATH2)%.o: $(SRC_PATH2)%.c
	@printf "\r$(EOLCLR)[$(NAME_P)] compiling\t\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) -I./includes -I./libft/includes -o $@ -c $<
	@printf '\t'$(OK)

libft :
	@make -C ./printf

clean :
	@printf "[$(NAME_P)] removing\t\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJ_PATH1)
	@rm -rf $(OBJ_PATH2)
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
