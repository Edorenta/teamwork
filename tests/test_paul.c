#include "push_swap.h"
#include <stdio.h>

#include "parser.c"
#include "parser_utils.c"
#include "piles_utils.c"
#include "str_utils.c"
#include "ext_sort.c"

void			put_error(t_env *env, const char *err_msg)
{
	free_piles(env);
	pstr(2, err_msg, '\n');
	exit(1);
}

inline static void		init_env(t_env *env, int ac)
{
	env->size = ac - 1;
	env->first_move = NULL;
	env->last_move = NULL;
	env->a = NULL;
	env->b = NULL;
	env->c = NULL;
	env->a1 = 0;
	env->b1 = 0;
}

inline static void		deinit_env(t_env *env)
{
	free_piles(env);
}

int				test_paul(int ac, char **av)
{
	t_env env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	for (int i = 0; i <= env.size - 1; i++)
		printf("a[%d] = %ld\n", i, env.a[i]);
	//sort_pile(&env);
	deinit_env(&env);
	return (1);
}
