/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 04:24:50 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 04:30:31 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** applique les casts de modificateur de longueur pour les types unsigned
 ** present en argument, et garde le plus grand si plusieurs sont envoyé
*/

void	apply_modifier_unsigned(t_printf *data, t_type *specifier)
{
	if ((data->flag[0] & flag_L))
		specifier->l = (long double)specifier->l;
	else if ((data->flag[0] & flag_j))
		specifier->l = (uintmax_t)specifier->l;
	else if ((data->flag[0] & flag_z))
		specifier->l = (size_t)specifier->l;
	else if ((data->flag[0] & flag_l))
		specifier->l = (unsigned long)specifier->l;
	else if ((data->flag[0] & flag_h))
		specifier->l = (unsigned short)specifier->l;
	else if ((data->flag[0] & flag_hh))
		specifier->l = (unsigned char)specifier->l;
}

/*
 ** applique les casts de modificateur de longueur pour les types signed
 ** present en argument, et garde le plus grand si plusieurs sont envoyé
*/

void	apply_modifier_signed(t_printf *data, t_type *specifier)
{
	if ((data->flag[0] & flag_L))
		specifier->l = (long double)specifier->l;
	else if ((data->flag[0] & flag_j))
		specifier->l = (intmax_t)specifier->l;
	else if ((data->flag[0] & flag_z))
		specifier->l = (ssize_t)specifier->l;
	else if ((data->flag[0] & flag_l))
		specifier->l = (long)specifier->l;
	else if ((data->flag[0] & flag_h))
		specifier->l = (short)specifier->l;
	else if ((data->flag[0] & flag_hh))
		specifier->l = (char)specifier->l;
}
