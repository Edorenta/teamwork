/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:37:38 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/25 18:42:02 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ns;

	if (!s || !f)
		return (NULL);
	i = 0;
	ns = ft_strnew(ft_strlen(s));
	if (ns == NULL)
		return (NULL);
	while (s[i])
	{
		ns[i] = (*f)(i, s[i]);
		++i;
	}
	ns[i] = '\0';
	return (ns);
}
