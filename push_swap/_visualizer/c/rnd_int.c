/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rnd_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:47:58 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/04 20:06:27 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	seed(void)
{
	size_t			epoch_seed;
	size_t			a_seed;
	size_t			seed;
	size_t			*x;

	epoch_seed = (size_t)time(NULL);
	a_seed = (size_t)&x % 1111;
	a_seed = !a_seed ? 1 : a_seed;
	seed = epoch_seed / (a_seed %= 1111);
	srand(seed);
}

int		main (int ac, char **av)
{
	time_t			t;
	int				r;
	int				unique;
	unsigned int	n;
	unsigned int	max;
	unsigned int	list[n];
	unsigned int	min;
	unsigned int	range;
	unsigned int	buckets = RAND_MAX / range;
	unsigned int	limit;

	n = ac > 1 ? atoi(av[1]) : 500;
	min = ac > 2 ? atoi(av[2]) : 0;
	max = ac > 3 ? atoi(av[3]) : 1000;
	if ((max - min + 1) < n)
	{
		dprintf(2, "<!> impossible to generate %d unique integers in [%d;%d]\n", n, min, max);
		max = min + n - 1;
		dprintf(2, "<!> interval reset to [%d;%d]\n", min, max);
	}
	range = 1 + max - min;
	range = range < 1 ? 1 : range;
	buckets = RAND_MAX / range;
	limit = buckets * range;
	seed();
	for (int i = 0; i < n; i++)
	{
		unique = 1;
		do
			r = rand();
		while (r >= limit);
		buckets = buckets < 1 ? 1 : buckets;
		list[i] = (min + (r / buckets));
		for (int j = 0; j < i && unique; j++)
			unique = list[j] == list[i] ? 0 : unique;
		unique ? printf("%d", list[i]) : (--i);
		if (unique)
			i == (n - 1) ? printf("%c", '\n') : printf("%c", ' ');
	}
	return (0);
}
