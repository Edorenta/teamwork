#include "push_swap.h"
#include <stdio.h>

#include "move.c"

static print_list(long *lst, int size)
{
	for (int i = 0; i < size; i++)
		printf("%ld \n", lst[i]);
}

void test_flo()
{
	t_env *env;

	env = malloc(sizeof(t_env));
	env->a = malloc(sizeof(long) * 5);
	env->b = malloc(sizeof(long) * 5);
	env->size = 5;
	for (int i = 0; i < env->size ; i++)
	{
		env->a[i] = i + 1;
		env->b[i] = 0;
	}
	print_list(env->a, env->size);
	print_list(env->b, env->size);
}
