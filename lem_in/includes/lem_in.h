#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
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
long			fatol(t_env *env, const char *str);
int				scmp(const char *s1, const char *s2);
void			init_env(t_env *env);
void			deinit_env(t_env *env);

/*
 * IO
 */

int				interpret_line(t_env *env, const char *p);
void			free_lines(t_env *env);
int				get_lines(t_env *env);
void			put_lines(t_env *env);

/*
 * ERROR MANAGEMENT
 */

void			sig_handler(int sig);
void			put_error(t_env *env, const char *err_msg);
int				anthill_complete(t_env *env);

/*
 * LINKS
 */

t_link			*add_link(t_room *new_linked_room, t_link *prev_link);
void			new_link(t_env *env, t_room *room1, t_room *room2);
void			link_rooms(t_room *room1, t_room *room2);

/*
 * ROOMS
 */

void			new_room(t_env *env, char *name, long x, long y);
t_room			*str_to_room(t_env *env, const char *s);

/*
 * ANTS
 */

void			put_ant(t_ant *ant);
void			ant_add_path(t_env *env, t_ant *ant, t_room *room);
void			move_ant_forward(t_env *env, t_ant *ant);
t_ant			*new_ant(t_env *env, t_path *path);
void			del_ant(t_ant *ant);

/*
 * PATHS
 */

t_path			*new_path(t_env *env);
t_path			*duplicate_path(t_env *env, t_path *path);
void			add_path(t_env *env, t_path *path, t_room *room);
void			del_path(t_path *path);
void			put_path(t_path *path);

/*
 * PRINT
 */

void			put_all(t_env *env);
void			put_room(t_env *env, t_room *r);
void			put_rooms(t_env *env);
void			put_link(t_env *env, t_parsed_link *l);
void			put_links(t_env *env);
void			put_room_links(t_env *env, t_room *room);

/*
 * SOLVE
 */

void			solve(t_env *env);

#endif
