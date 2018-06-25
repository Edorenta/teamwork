SRC = asm.c \
      lexer.c \
      lexer_basic.c \
      lexer_ins.c \
      op.c \
      token.c \
      check.c \
      utils.c

LIB = ../../printf/libftprintf.a
INC = -I../../includes -I../../printf/includes -I../../printf/libft/includes
LUB = -lftprintf
NAME = asm


all :
	clang $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm ../../rsrc/examples/bee_gees.s

val :
	clang $(SRC) $(LIB) $(INC) -o $(NAME)
	valgrind ./asm ../../rsrc/examples/bee_gees.s

