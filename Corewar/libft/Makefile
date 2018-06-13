CC =			gcc
NAME =			libft.a
SRC_DIR =		./
# SRC_DIR_PRINTF =./ft_printf/
OBJ_DIR =		./obj/
# OBJ_DIR_PRINTF =./obj/ft_printf/
HEADER =		./include
CFLAGS =		-Wall -Werror -Wextra
DEBUG_FLAGS =	-fsanitize=address -g
ARFLAGS =		-rcs
CFILES =		ft_putchar ft_putchar_fd ft_putstr ft_putstr_fd						\
				ft_putnbr ft_putnbr_fd ft_putendl ft_putendl_fd						\
				ft_strcpy ft_strncpy ft_strdup										\
				ft_strlen ft_strcmp ft_strncmp ft_strcat ft_strncat ft_strlcat ft_strtrim ft_strjoin ft_strsub			\
				ft_bzero ft_memalloc ft_memdel ft_memset ft_memmove ft_memcpy ft_memccpy ft_memcmp ft_memchr ft_strstr ft_strnstr 		\
				ft_isascii ft_isdigit ft_isalpha ft_isalnum ft_isspace ft_isprint	\
				ft_toupper ft_tolower ft_atoi ft_itoa ft_ulltoa_base ft_lltoa_base \
				ft_strclr ft_striter ft_striteri ft_strnew ft_strdel ft_strequ ft_strnequ ft_strmap ft_strmapi ft_strchr ft_strrchr ft_strsplit\
				ft_swap ft_range ft_sqrt ft_pow ft_abs\
				ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap get_next_line \
				apply ft_printf modifier ft_printf_parser spec_conv spec_decimal spec_type spec_unicode

SRC =			$(CFILES:%=$(SRC_DIR)%.c)
# SRC_PRINTF =	$(CFILES_PRINTF:%=$(SRC_DIR_PRINTF)%.c)
OBJ =			$(SRC:%.c=$(OBJ_DIR)%.o)
# OBJ_PRINTF =	$(SRC_PRINTF:%.c=$(OBJ_DIR_PRINTF)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar $(ARFLAGS) $@ $(OBJ)
	@echo $@ Done !

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -I$(HEADER) -o $@ $(CFLAGS)

# $(OBJ_DIR)%.o: $(SRC_DIR_PRINTF)%.c
	# mkdir -p $(OBJ_DIR)
	# $(CC) -c $< -I$(HEADER) -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

#Regles qui ne concerne pas des noms de fichiers
.PHONY: clean fclean re
#Enleve les directives implicites par defauts
.SUFFIXES:
