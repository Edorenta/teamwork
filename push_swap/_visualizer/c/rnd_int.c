/* RANDOM UNIQUE INTEGER LIST GENERATOR by pde-rent */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int ac, char **av)
{
	time_t			t;
    int 			r;
    int 			unique;
    unsigned int 	n = ac > 1 ? atoi(av[1]) : 500;
	unsigned int 	list[n];
    unsigned int 	min = ac > 2 ? atoi(av[2]) : 0;
    unsigned int 	max = ac > 3 ? atoi(av[3]) : 1000;
	if ((max - min + 1) < n)
	{
		dprintf(2, "impossible to generate %d unique integers in [%d;%d]\n", n, min, max);
		max = min + n - 1;
		dprintf(2, "interval reset to [%d;%d]\n", min, max);
	}
    unsigned int 	range = 1 + max - min;
    unsigned int 	buckets = RAND_MAX / range;
    unsigned int 	limit = buckets * range;
	dprintf(2, "generating %d random integers in [%d;%d] in list.txt\n", n, min, max);
	srand((unsigned) time(&t));
	for(int i = 0; i < n; i++)
	{	
		unique = 1;
    	do
        	r = rand();
    	while (r >= limit);
    	list[i] = (min + (r / buckets));
    	for (int j = 0; j < i && unique; j++)
    		unique = list[j] == list[i] ? 0 : unique;
		unique ? printf("%d", list[i]) : (--i);
		if (unique)
			i == (n - 1) ? printf("%c", '\n') : printf("%c", ' ');
	}
	return(0);
}
