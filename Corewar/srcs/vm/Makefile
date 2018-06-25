SRC = 	corewar.c check_arg.c parse_player.c player.c parse_op.c check_ocp.c \
 		show.c process.c get_arg.c core.c op.c \
		\
		ncurses/ncurses.c \
		\
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
		opcode/fork.c \

LIB = ../../libft/libft.a ../../printf/libftprintf.a
INC = -I../../includes -I../../libft/includes
LUB = -lft.a
NAME = corewar

all :
	#rm -f exe.cor
	#rm -f asm
	# gcc -lncurses $(SRC) $(LIB) $(INC) -o $(NAME) -g -fsanitize=address
	gcc -lncurses $(SRC) $(LIB) $(INC) -o $(NAME) -g
