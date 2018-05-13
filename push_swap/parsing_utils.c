/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:25:31 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/05/12 12:06:27 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			slen(char *s)
{
	return (*s ? slen(++s) + 1 : 0);
}

int			pstr(const char *s)
{
	*s ? write(1, s, slen(s)) : 0;
	write(1, "\n", 1);
}

int			is_space(const char c)
{
	return ((c < 14 && c > 7) || c == 32);
}

int			is_digit(const char c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}

int			space_in(const char *str)
{
	const char	*p = str;
	int			i;
	int			prev;

	prev = 1;
	i = 0;
	while (*p)
	{
		(is_space(*p) && !prev) ? i++ : 0;
		prev = is_space(*p) ? 1 : 0;
		p++;
	}
	return (prev ? (i - 1) : i);
}

int			full_digits(const char *str)
{
	return (ft_atol(str) != NONE ? 1 : 0);
}

int			is_int(char *av)
{
	return (av && (ft_atol(av) >= INT_MIN && ft_atol(av) <= INT_MAX));
}

long		ft_atol(const char *str)
{
	long		nb;
	long		sign;

	nb = NONE;
	while (is_space(*str))
		++str;
	if (*str)
	{
		sign = *str == '-' ? -1 : 1;
		if (*str == '+' || *str == '-')
			++str;
		nb = 0;
		while (*str && is_digit(*str))
			nb = 10 * nb + (*str++ - '0');
	}
	return (*str == NULL ? nb * sign : NONE);
}
