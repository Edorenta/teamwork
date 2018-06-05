/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:49:05 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/06/05 17:43:17 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		move_ant(t_env *env, t_ant *ant)
{
	if (ant->path->len > 0 && ant->path->next_room->ant == NULL)
	{
		ant->path->current->ant = NULL;
		ant->path->current = ant->path->next;
		ant->path->current->ant = ant;
		pstr(1, "L", '\0');
		plong(1, i, '\0');
		pstr(1, "-", '\0');
		pstr(1, &(ant->path->current->id[0]), '\0');
	}
}


void		move_colony(t_env *env)
{
	int		i;

	while (env->colony[nb_ants - 1]->path->current != env->end)
	{
		i = -1;
		while (++i < nb_ants)
			move_ant(env, env->colony[i]);
		pstr(1, "\n", '\0');
	}
}
