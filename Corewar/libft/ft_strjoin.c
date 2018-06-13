/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:37:01 by jjourne           #+#    #+#             */
/*   Updated: 2017/05/18 01:29:23 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ns;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (ft_strdup((!s1) ? s2 : s1));
	i = -1;
	j = -1;
	ns = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ns == NULL)
		return (NULL);
	while (s1[++i])
		ns[i] = s1[i];
	while (s2[++j])
		ns[i++] = s2[j];
	ns[i] = '\0';
	return (ns);
}
