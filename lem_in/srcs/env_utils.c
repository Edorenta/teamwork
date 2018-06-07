#include "lem_in.h"

static void	free_colony(t_env *env)
{
	int i;

	i = env->nb_ants;
	while (--i >= 0)
		env->colony[i] ? free(env->colony[i]) : 0;
	env->colony ? free(env->colony) : 0;
}

static void	free_rooms(t_env *env)
{
	t_parsed_room *parsed;

	parsed = env->parsed_room;
	while (parsed && parsed->next)
	{
		parsed = parsed->next;
		parsed->prev->room->link ? free(parsed->prev->room->link) : 0;
		parsed->prev->room ? free(parsed->prev->room) : 0;
		parsed->prev ? free(parsed->prev) : 0;
	}
	parsed->room ? free(parsed->room) : 0;
	parsed ? free(parsed) : 0;
}

static void	free_parsed_links(t_env *env)
{
	t_parsed_link *parsed;

	parsed = env->parsed_link;
	while (parsed && parsed->next)
	{
		parsed = parsed->next;
		parsed->prev ? free(parsed->prev) : 0;
	}
	parsed ? free(parsed) : 0;
}

void		init_env(t_env *env)
{
	env->start = NULL;
	env->end = NULL;
	env->nb_rooms = 0;
	env->nb_ants = 0;
	env->colony = NULL;
	env->parsed_room = NULL;
	env->parsed_link = NULL;
}

void		deinit_env(t_env *env)
{
	free_rooms(env);
	free_parsed_links(env);
	free_colony(env);
}