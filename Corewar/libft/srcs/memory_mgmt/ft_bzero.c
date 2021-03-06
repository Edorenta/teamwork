/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:06:43 by pde-rent          #+#    #+#             */
/*   Updated: 2017/12/01 13:19:53 by pde-rent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_mgmt.h"

void	ft_bzero(void *mem, size_t n)
{
	while (n-- > 0)
		*(char*)mem++ = 0;
}
