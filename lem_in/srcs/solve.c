#include "lem_in.h"

void	solve(t_env *env)
{
	put_room_links(env, env->start);
	put_room_links(env, env->end);
}
