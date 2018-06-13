/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:39:53 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 04:43:13 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*sizemallocstr(char *str, unsigned long long n,
	unsigned int base)
{
	int i;

	i = 0;
	while ((n >= base && (++i)))
		n /= base;
	if (!(str = ft_strnew(i + 1)))
		exit(EXIT_FAILURE);
	return (str);
}

static char		convert_char_base(unsigned long long n)
{
	char c;

	if (n > 9)
		c = n - 10 + 'a';
	else
		c = n + '0';
	return (c);
}

static void		nbr_to_str(char *str, unsigned int *i,
	unsigned long long n, unsigned int base)
{
	if (n >= base)
	{
		nbr_to_str(str, i, n / base, base);
		nbr_to_str(str, i, n % base, base);
	}
	else
		str[(*i)++] = convert_char_base(n);
}

char			*ft_ulltoa_base(unsigned long long n, unsigned int base)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = NULL;
	str = sizemallocstr(str, n, base);
	nbr_to_str(str, &i, n, base);
	return (str);
}
