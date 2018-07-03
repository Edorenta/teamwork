SRC = asm.c \
      op.c \
      main.c \
      parser.c \
      lexer.c \
      lexer_basic.c \
      lexer_ins.c \
      struct_iter.c \
      struct_lab.c \
      struct_ops.c \
      struct_token.c \
      check.c \
      utils.c \
      utils_ops.c \
      utils_lab.c \
      utils_iter.c \
      utils_parser.c \
      utils_lexer.c \
      write.c \
      error.c \
	  params.c \
	  params_three.c

CFLAGS = -Wall -Werror -Wextra
LIB = ../../libft/libft.a
INC = -I../../includes -I../../libft/includes
LUB = -lft
NAME = asm
FILE = ./#../../rsrc/examples/code/
TARGET = THUNDER

all :
	@rm -f test.cor
	@clang $(SRC) $(LIB) $(INC) -o $(NAME)
	./asm $(FILE)$(TARGET).s

val :
	clang $(SRC) $(LIB) $(INC) -o $(NAME)
	valgrind --leak-check=full --track-origins=yes ./asm ../../rsrc/examples/code/bee_gees.s

clean :
	rm -rf asm.dSym

fsan :
	clang -ggdb -fsanitize=address -fno-omit-frame-pointer $(SRC) $(LIB) $(INC) -o $(NAME)

lldb :
	clang -g -Wall -Werror -Wextra $(SRC) $(LIB) $(INC) -o $(NAME)
