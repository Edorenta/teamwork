NAME    		= corewar

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra
DEBUG_FLAGS =		-fsanitize=address -g

HEADER_DIR 		= ./includes/
HEADER_LIBFT_DIR = ./libft/includes

LIBFT_DIR 		= ./libft/
LIBFT 			= $(LIBFT_DIR)libft.a
OBJ_DIR =			./obj/

SRCS =			srcs/vm/corewar.c check_arg.c parse_player.c \
				srcs/vm/player.c parse_op.c check_ocp.c \
				srcs/vm/show.c process.c get_arg.c \
				srcs/vm/core.c op.c tools.c \
				srcs/vm/flib.c action_proc.c client.c \
				srcs/vm/opcode/live.c \
				srcs/vm/opcode/ld.c \
				srcs/vm/opcode/st.c \
				srcs/vm/opcode/add.c \
				srcs/vm/opcode/sub.c \
				srcs/vm/opcode/and.c \
				srcs/vm/opcode/or.c \
				srcs/vm/opcode/xor.c \
				srcs/vm/opcode/zjmp.c \
				srcs/vm/opcode/ldi.c \
				srcs/vm/opcode/sti.c \
				srcs/vm/opcode/lld.c \
				srcs/vm/opcode/lldi.c \
				srcs/vm/opcode/lfork.c \
				srcs/vm/opcode/aff.c \
				srcs/vm/opcode/fork.c \

all: $(NAME_1) $(NAME_2)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(SRC) -I$(HEADER_DIR) -I$(HEADER_LIBFT_DIR) libft/libft.a -o $@ $(CFLAGS) #$(DEBUG_FLAGS)

$(OBJ_DIR)%.o: $(SRCS)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo clean $@ Done !

fclean:	clean
	rm -f $(NAME_1)
	rm -f $(NAME_2)
	@make -C $(LIBFT_DIR) fclean
	@echo fclean $@ Done !

re:		fclean all

.PHONY: clean fclean re
.SUFFIXES:
