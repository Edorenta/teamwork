/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:37:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/25 18:30:45 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ns;

	if (!s || !f)
		return (NULL);
	i = 0;
	ns = ft_strnew(ft_strlen(s));
	if (ns == NULL)
		return (NULL);
	while (s[i])
	{
		ns[i] = (*f)(s[i]);
		++i;
	}
	ns[i] = '\0';
	return (ns);
}
