SRC = asm.c \
      lexer.c \
      lexer_basic.c \
      lexer_ins.c \
      op.c \
      token.c \
      check.c \
      utils.c

LIB = ../../libft/libft.a
INC = -I../../includes -I../../libft/includes
LUB = -lft
NAME = asm


all :
	clang $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm ../../rsrc/examples/bee_gees.s

val :
	clang $(SRC) $(LIB) $(INC) -o $(NAME)
	valgrind --leak-check=full ./asm ../../rsrc/examples/bee_gees.s

clean :
	rm -rf asm asm.dSym/

fsan :
	clang -fsanitize=address $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm ../../rsrc/examples/bee_gees.s
