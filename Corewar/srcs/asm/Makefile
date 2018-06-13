SRC = asm.c lexer.c op.c
LIB = ../../printf/libftprintf.a
INC = -I../../includes -I../../printf/includes -I../../printf/libft/includes
LUB = -lftprintf
NAME = asm


all :
	#rm -f exe.cor
	#rm -f asm
	gcc -g $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm	
	#hexdump -C exe.cor
