#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by pde-rent          #+#    #+#              #
#    Updated: 2018/06/11 15:24:45 by fmadura          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libftprintf.a
NAME_P		= ft_printf
FILES		=	ft_vasprintf		ft_printf		ft_vprintf					\
				fmt_parser			fmt_converter	fmt_debug					\
				fmt_dcdiu			fmt_fcf			fmt_ecegcg					\
				fmt_aca				fmt_ocoxcx		fmt_cccscsr					\
				fmt_bpn				fmt_customfb	fmt_customfns				\
				fmt_converter2

SRCS		= $(addprefix $(SRCS_PATH),$(addsuffix .c,$(FILES)))
OBJS		= $(addprefix $(OBJS_PATH),$(addsuffix .o,$(FILES)))

LFTDIR		= libft
COMPILER	= gcc
LINKER		= ar rc
SRCS_PATH	= srcs/
I_PATH		= includes/
OBJS_PATH	= objs/
INCLUDES	= -I $(I_PATH) -I $(LFTDIR)/includes
LFLAGS		= -L $(LFTDIR) -lft
CFLAGS		= -Wall -Wextra -g $(INCLUDES) #-pedantic

#color
BLACK		= "\033[1;30m"
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"
EOC			= "\033[0;0m"

#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"dependencies compiled\t"$(OK)'\n'
	@printf "[$(NAME_P)] running\t$(WHITE)ar rc $@$(WHITE)"
	@$(LINKER) $(NAME) $(OBJS) $(LFTDIR)/objs/*.o
	@printf '\t'$(OK)'\n'
	@printf "[$(NAME_P)] running\t$(WHITE)ranlib $@$(WHITE)"
	@ranlib $(NAME)
	@printf '\t'$(OK)'\n'
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

$(OBJS) : | $(OBJS_PATH)

$(OBJS_PATH) :
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@printf "$(EOLCLR)[$(NAME_P)] compiling\t$(BOLD)$(YELLOW)$<$(WHITE)\r"
	@$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LFTDIR) clean
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj files$(WHITE)"
	@rm -rf $(OBJS_PATH)
	@rm -f $(OBJS_TRACKER)
	@printf '\t\t'$(OK)'\n'

fclean:
	@$(MAKE) -C $(LFTDIR) fclean
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj files$(WHITE)"
	@rm -rf $(OBJS_PATH)
	@rm -f $(OBJS_TRACKER)
	@printf '\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] erasing\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t'$(OK)'\n'

re: fclean all

norm:
	@echo $(RED)
	@norminette $(SRCS) $(I_PATH) | grep -v	Norme -B1 || true
	@echo $(END)

.PHONY: all clean fclean re test norme
