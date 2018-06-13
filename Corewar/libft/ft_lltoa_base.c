/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:43:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 04:44:24 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*sizemallocstr(char *str, long long n, int base)
{
	int i;

	i = 0;
	while ((n >= base || (n < 0 && -base > n)) && (++i))
		n /= base;
	if (!(str = ft_strnew(i + 1)))
		exit(EXIT_FAILURE);
	return (str);
}

static char		convert_char_base(long long n)
{
	char c;

	if (n > 9)
		c = n - 10 + 'a';
	else
		c = n + '0';
	return (c);
}

static void		nbr_to_str(char *str, unsigned int *i, long long n, int base)
{
	int sign;

	sign = (n < 0) ? -1 : 1;
	if (n >= base || n <= -base)
	{
		nbr_to_str(str, i, n / base * sign, base);
		nbr_to_str(str, i, n % base, base);
	}
	else
		str[(*i)++] = convert_char_base(n * sign);
}

char			*ft_lltoa_base(long long n, int base)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = NULL;
	str = sizemallocstr(str, n, base);
	nbr_to_str(str, &i, n, base);
	return (str);
}
