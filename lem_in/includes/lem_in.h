#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "anthill.h"

/*
 * BASICS
 */

int				slen(char *s);
long			labs(long n);
int				active_bits(char c);
int				is_space(const char c);
int				is_digit(const char c);
int				plong(int fd, long n, char end);
int				pstr(int fd, const char *s, char end);
int				scat(char *dest, const char *src, char c);
long			ft_atol(const char *str);
int				scmp(const char *s1, const char *s2);
void			init_env(t_env *env, int ac);
void			deinit_env(t_env *env);

/*
 * IO
 */

int				interpret_line(t_env *env, const char *p);
int				get_lines(t_env *env);

/*
 * ERROR MANAGEMENT
 */

void			sig_handler(int sig);
void			put_error(t_env *env, const char *err_msg);

/*
 * LINKS
 */

/*
 * ROOMS
 */

/*
 * ANTS
 */
