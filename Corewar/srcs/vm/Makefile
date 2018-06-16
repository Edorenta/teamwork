SRC = corewar.c check_arg.c parse_player.c player.c parse_op.c check_ocp.c \
 		show.c process.c get_arg.c core.c op.c \
		\
		opcode/live.c
LIB = ../../libft/libft.a
INC = -I../../includes
# INC = -Iinc_tmp/
LUB = -llibft.a
NAME = corewar


all :
	#rm -f exe.cor
	#rm -f asm
	gcc -g $(SRC) $(LIB) $(INC) -o $(NAME)
	#hexdump -C exe.cor
