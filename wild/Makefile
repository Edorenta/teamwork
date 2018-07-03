# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:13:34 by jyildiz-          #+#    #+#              #
#    Updated: 2018/02/13 16:44:07 by jyildiz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all $(NAME) objet fclean re
CLEAN_OBJ = \033[91m=> Deleting objects ...\033[0m
CLEAN_ALL = \033[91m=> Deleting libftprintf.a ...\033[0m
CLEAN_OBJ_OK = \033[92m==> Deleting objects done\033[0m
CLEAN_ALL_OK = \033[92m==> Deleting libftprintf.a done\033[0m
BUILD_OBJ = \033[91m=> Building objects...\033[0m
BUILD_PRINT = \033[91m==> Building libftprintf.a...\033[0m
BUILD_OK = \033[92m===> Building done !\033[0m
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft/libft.h
SRCS = ft_printf.c ft_handler.c ft_arg.c ft_conv_d.c ft_itoabase.c ft_buf.c \
	   ft_conv_u.c ft_conv_o.c ft_conv_x.c ft_conv_c.c ft_putwchar.c \
	   ft_conv_s.c ft_conv_per.c ft_fill.c
OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): objet library
	@ echo "\n$(BUILD_PRINT)"
	@ ar rc $(NAME) $(OBJ) 
	@ ranlib $(NAME)
	@ echo "$(BUILD_OK)\n"

library:
	@ cd libft; $(MAKE)
	@ cd libft; cp $(NAME) ..

objet:
	@ echo "$(BUILD_OBJ)"
	@ gcc  $(CFLAGS) -c $(SRCS) -I $(NAME)

clean:
	@ echo "\n$(CLEAN_OBJ)"
	@ rm -rf $(OBJ)
	@ cd libft; $(MAKE) clean
	@ echo "$(CLEAN_OBJ_OK)\n"

fclean: clean
	@ echo "$(CLEAN_ALL)"
	@ rm -rf $(NAME)
	@ cd libft; $(MAKE) fclean
	@ echo "$(CLEAN_ALL_OK)\n"

re: fclean all
