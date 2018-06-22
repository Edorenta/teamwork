SRC = asm.c \
	  lexer.c \
	  lexer_basic.c \
	  op.c \
	  token.c \
	  check.c
LIB = ../../printf/libftprintf.a
INC = -I../../includes -I../../printf/includes -I../../printf/libft/includes
LUB = -lftprintf
NAME = asm


all :
	#rm -f exe.cor
	#rm -f asm
	clang  $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm ../../rsrc/examples/bee_gees.s
