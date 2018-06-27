SRC = asm.c \
	  main.c \
      lexer.c \
      parser.c \
      lexer_basic.c \
      lexer_ins.c \
      op.c \
	  struct_iter.c \
      struct_ops.c \
      struct_token.c \
      check.c \
      utils.c
CFLAGS = -Wall -Werror -Wextra
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
	rm -rf asm.dSym

fsan :
	clang -fsanitize=address $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm ../../rsrc/examples/bee_gees.s

lldb :
	clang -g -Wall -Werror -Wextra $(SRC) $(LIB) $(INC) -o $(NAME)
	lldb ./asm ../../rsrc/examples/bee_gees.s
