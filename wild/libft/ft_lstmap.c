/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:43:59 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 18:59:25 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	start = new;
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	tmp = NULL;
	new = start;
	return (new);
}
