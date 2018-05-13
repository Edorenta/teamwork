#include "push_swap.h"
#include <stdio.h>

#include "move.c"

void test_swap()
{
	long *test;

	test = malloc(sizeof(long) * 3);
	test[0] = 1;
	test[1] = 2;
	test[2] = 3;
	int size = 3;
	int felem = 1;
	printf("before : %ld\n", test[0]);
	printf("before : %ld\n", test[1]);
	printf("before : %ld\n", test[2]);
	test = swap(test, size, felem);
	printf("after : %ld\n", test[0]);
	printf("after : %ld\n", test[1]);
	printf("after : %ld\n", test[2]);
}

void test_push()
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
	env->a1 = 0;
	env->b1 = 4;
	env = push(env);
	printf("%ld\n", env->a[0]);
	printf("%ld\n", env->a[1]);
	printf("%ld\n", env->a[2]);
	printf("%ld\n", env->a[3]);
	printf("%ld\n", env->a[4]);
	printf("%ld\n", env->b[0]);
	printf("%ld\n", env->b[1]);
	printf("%ld\n", env->b[2]);
	printf("%ld\n", env->b[3]);
	printf("%ld\n", env->b[4]);
}