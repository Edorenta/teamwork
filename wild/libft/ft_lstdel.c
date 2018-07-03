/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:46:53 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 20:04:11 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *next;

	if (!(*alst) || !(del))
		return ;
	tmp = *alst;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(&tmp, del);
		tmp = next;
	}
	*alst = NULL;
}
