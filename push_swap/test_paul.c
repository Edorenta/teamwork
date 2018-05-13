#include "push_swap.h"
#include <stdio.h>

#include "parser.c"
#include "parser_utils.c"
#include "piles_utils.c"
#include "str_utils.c"

void			put_error(t_env *env, const char *err_msg)
{
	free_piles(env);
	pstr(err_msg);
	exit(1);
}

inline void		init_env(t_env *env)
{
	env->size = ac;
	env->a = NULL;
	env->b = NULL;
	env->a1 = 0;
	env->b1 = 0;
}

inline void		deinit_env(t_env *env)
{
	free_piles();
}

int				test_paul(int ac, char **av)
{
	t_env env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(ac, av, &env))
		put_error(env, Error);
	for (int i = 0; i = env->size; i++)
		printf("a[%d] = %d\n", env->a[i]);
	sort_pile(&env);
	deinit_env(&env);
	return (1);
}
