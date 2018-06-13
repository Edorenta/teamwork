/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 09:02:41 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 05:19:52 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** recherche dans le tableau d pointeur sur foncion le bon argument envoyé
** en parametre et l'execute.
*/

void	apply_specifier(t_printf *data, va_list vl)
{
	int						i;
	char					*str_arg;
	int						len_arg;
	t_type					specifier;
	static int const *const tab_ptr_get_spec[18] =
	{(void*)"s", (void*)&spec_s, (void*)"S", (void*)&spec_ls,
	(void*)"p", (void*)&spec_p, (void*)"dDi", (void*)&spec_d,
	(void*)"oO", (void*)&spec_o, (void*)"uU", (void*)&spec_u,
	(void*)"xX", (void*)&spec_x, (void*)"c", (void*)&spec_c,
	(void*)"C", (void*)&spec_lc};

	i = -2;
	len_arg = 0;
	specifier.l = 0;
	data->val_prefix = 0;
	while ((i += 2) < (9 * 2))
		if (ft_strchr((char*)tab_ptr_get_spec[i], data->format[data->format_i]))
			len_arg = ((t_ptr_get_spec)tab_ptr_get_spec[i + 1])(data, vl,
					specifier, &str_arg);
	if ((data->flag[0] & flag_plus) && (data->flag[0] & flag_space))
		data->flag[0] &= ~flag_space;
	if ((data->flag[0] & flag_neg) && (data->format[data->format_i] != 'p'))
		data->flag[0] &= ~flag_zero;
	data->effective_fw = apply_effective_value(data, len_arg);
	apply_print_f(data, str_arg);
}

/*
** applique les differentes etapes (obligatoire et optionnel) de printf,
** dans l'ordre:
** 1 - la largeur de champ
** 2 - les prefix
** 3 - la largeur apres les prefix si besoin
** 4 - ajoute la precision
** 5 - la valeur de l'argument dans va_arg
** 6 - et la largeur de champ de fin
*/

void	apply_print_f(t_printf *data, char *str_arg)
{
	if ((data->flag[0] & flag_width) && !(data->flag[0] & flag_neg)
			&& !((data->flag[0] & flag_plus) && (data->flag[0] & flag_zero))
			&& !((data->flag[0] & flag_space) && (data->flag[0] & flag_zero))
			&& !((data->flag[0] & flag_hash) && (data->flag[0] & flag_zero)))
	{
		put_n_char_to_result(data, (data->flag[0] & flag_zero)
				? '0' : ' ', data->effective_fw);
	}
	if (data->val_prefix > 0)
		add_str_to_result(data, data->str_prefix, 1);
	if ((data->flag[0] & flag_width) && !(data->flag[0] & flag_neg)
			&& (((data->flag[0] & flag_plus) && (data->flag[0] & flag_zero))
			|| ((data->flag[0] & flag_space) && (data->flag[0] & flag_zero))
			|| ((data->flag[0] & flag_hash) && (data->flag[0] & flag_zero))))
		put_n_char_to_result(data, '0', data->effective_fw);
	if (data->flag[0] & flag_pre)
		put_n_char_to_result(data, '0', data->effective_pre);
	if (((data->format[data->format_i] == 'c') ||
				(data->format[data->format_i] == 'C')) && !(ft_strlen(str_arg)))
		add_to_result(data, ' ', 2);
	else
		add_str_to_result(data, str_arg, 1);
	apply_print_f_end(data, str_arg);
}

void	apply_print_f_end(t_printf *data, char *str_arg)
{
	if (((data->flag[0] & flag_width) && (data->flag[0] & flag_neg)))
		put_n_char_to_result(data, ((data->format[data->format_i] == 'p')
			&& (data->flag[0] & flag_zero)) ? '0' : ' ', data->effective_fw);
	ft_memdel((void**)&str_arg);
	ft_memdel((void**)&(data->str_prefix));
}

/*
** calcul les valeurs effective (la valeur reel a appliquer)
** de la precision et de la largeur de champ.
*/

int		apply_effective_value(t_printf *data, int len_arg)
{
	if (data->flag[0] & flag_pre)
	{
		if ((data->format[data->format_i] == 'c')
				|| (data->format[data->format_i] == 's')
				|| (data->format[data->format_i] == 'C')
				|| (data->format[data->format_i] == 'S'))
		{
			if (data->flag[2] < len_arg)
				data->effective_pre = data->flag[2];
		}
		else
		{
			if (data->flag[2] > len_arg)
				data->effective_pre = data->flag[2] - len_arg;
		}
	}
	if (data->flag[0] & flag_space)
	{
		data->val_prefix = 1;
		data->str_prefix = ft_strdup(" ");
	}
	if (data->flag[0] & flag_width)
		data->effective_fw = data->flag[1] - len_arg -
			data->effective_pre - data->val_prefix;
	return (data->effective_fw);
}
