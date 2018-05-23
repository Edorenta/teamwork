#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
#include "anthill.h"

/*
 * BASICS
 */

int				slen(char *s);
long			labs(long n);
int				is_space(const char c);
int				is_digit(const char c);
int				active_bits(char c);
int				plong(int fd, long n, char end);
int				pstr(int fd, const char *s, char end);
int				scat(char *dest, const char *src, char c);
void			init_env(t_env *env, int ac);
void			deinit_env(t_env *env);