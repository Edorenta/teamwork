/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:19:27 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 15:25:18 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (tmp)
	{
		if (content != NULL)
		{
			tmp->content = malloc(content_size);
			ft_memmove(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		else
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
	}
	tmp->next = NULL;
	return (tmp);
}
