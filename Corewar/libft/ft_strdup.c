/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:34:37 by jjourne           #+#    #+#             */
/*   Updated: 2017/01/25 19:28:34 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char *d;

	d = ft_strnew(ft_strlen(src));
	if (d == NULL)
		return (NULL);
	d = ft_strcpy(d, src);
	return (d);
}
