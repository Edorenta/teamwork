/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:41:02 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/02/15 18:52:47 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <locale.h>
# include <stdarg.h>
# include "libft/libft.h"
# define BUFF_SIZE 4096

typedef	struct	s_arg{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		width;
	int		precision;
	char	tab[2];
	char	conv;
}				t_arg;

typedef struct	s_buf{
	char			*buffer;
	int				nbchar;
	const char		*format;
	va_list			va;
	int				index;
}				t_buf;

void			ft_conv_d(t_arg *tmp, t_buf **buf);
t_buf			*init_buff(va_list va, const char *format);
void			init_arg(t_arg *arg);
int				ft_printf(const char *format, ...);
int				ft_flags(const char *format, t_arg *tmp);
int				ft_width(const char *format, va_list va, t_arg *tmp);
int				ft_precision(const char *format, va_list va, t_arg *tmp);
int				ft_length(const char *format, t_arg *tmp);
int				ft_arg(t_buf **buf, int index);
char			*ft_itoa_base(uintmax_t nbr, int base, int sign);
void			ft_strnconcat(t_buf **buf, const char *src, int nb);
void			ft_conv_u(t_arg *tmp, t_buf **buf);
void			ft_conv_o(t_arg *tmp, t_buf **buf);
void			ft_conv_x(t_arg *tmp, t_buf **buf, char c);
int				ft_conv_c(t_arg *tmp, t_buf **buf);
void			ft_putwchar(wchar_t c, int ret);
void			reboot_buf(t_buf **buf);
int				nb_wchar(wchar_t c);
int				ft_conv_c(t_arg *tmp, t_buf **buf);
int				ft_conv_s(t_arg *tmp, t_buf **buf);
int				nb_strwchar(wchar_t *c, int b);
int				test_strwchar(wchar_t *c, int b);
void			ft_conv_per(t_arg *tmp, t_buf **buf);
char			*fill_conv_d(intmax_t nb);
void			fill_conv_d2(t_arg *tmp, t_buf **buf, intmax_t nb, char *str);
intmax_t		ft_con_d(t_arg *tmp, t_buf **buf);
void			fill_conv_x(intmax_t nb, t_arg *tmp, t_buf **buf, char c);
void			fill_conv_x2(intmax_t nb, t_arg *tmp, t_buf **buf, char *str);
void			fill_conv_s(t_buf **buf, t_arg *tmp, int ret);
void			ft_wdth_s(t_arg *tmp, t_buf **buf, int ret);

#endif
