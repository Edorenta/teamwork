/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthill_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:49:05 by jyildiz-          #+#    #+#             */
/*   Updated: 2018/06/05 17:19:39 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		move_ant(s_env *env, int i)
{
	if (env->colony[i]->path->len > 0 && env->colony[i]->path->next_room->ant == NULL)
	{
		env->colony[i]->path->current->ant = NULL;
		env->colony[i]->path->current = env->colony[i]->path->next;
		env->colony[i]->path->current->ant = env->colony[i];
	}
}


void		move_colony(s_env *env)
{
	int		i;

	i = 0;
	while (i < s_env)
	{
		move_ant(env, i);
		i++;
	}
}

