SRC = asm.c lexer.c op.c token.c
LIB = ../../printf/libftprintf.a
INC = -I../../includes -I../../printf/includes -I../../printf/libft/includes
LUB = -lftprintf
NAME = asm


all :
	#rm -f exe.cor
	#rm -f asm
	clang  $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm ../../rsrc/examples/bee_gees.s
