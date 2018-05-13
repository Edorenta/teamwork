#include "push_swap.c"

int main(void)
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
