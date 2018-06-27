SRC = 	corewar.c check_arg.c parse_player.c player.c parse_op.c check_ocp.c \
 		show.c process.c get_arg.c core.c op.c \
		\
		client.c \
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

INC = -I../../includes -I ../../libft/includes
LIB = -L ../../libft -lft
NAME = corewar

all :
	#rm -f corewar
	# gcc -lncurses $(SRC) $(LIB) $(INC) -o $(NAME) -g -fsanitize=address
	gcc -lncurses $(SRC) $(INC) $(LIB) -o $(NAME) -g

clean : 
	rm -rf corewar.dSym

fsan :
	gcc -lncurses $(SRC) $(INC) $(LIB) -o $(NAME) -g -fsanitize=address

val :
	gcc -lncurses $(SRC) $(LIB) $(INC) -o $(NAME) -g
	valgrind ./corewar ../../rsrc/champs/42.cor

