#include "push_swap.h"
#include <stdio.h>

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

int				test_ervan(int ac, char **av)
{
	t_env env;

	init_env(&env, ac);
	if (ac < 2 || !av[1] || !arg_to_piles(&env, ac, av))
		put_error(&env, "Error: wrong input");
	for (int i = 0; i <= env.size - 1; i++)
		printf("a[%d] = %ld\n", i, env.a[i]);
	bb_sort(&env);
	ft_index(&env);
	for (int i = 0; i <= env.size - 1; i++)
		printf("c[%d] = %ld\n", i, env.c[i]);
	printf("is_sort : %d, all_sort : %d\n", is_sort(env.a, env.size, 0), all_sort(&env));
	for (int i = 0; i <= env.size - 1; i++)
		printf("a[%d] = %ld\n", i, env.a[i]);
	deinit_env(&env);
	return (1);
}
