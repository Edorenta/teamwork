#ifndef ANTHILL_H
# define ANTHILL_H

typedef struct s_path	t_path;
typedef struct s_room	t_room;
typedef struct s_ant	t_ant;
typedef struct s_env	t_env;
typedef struct s_links	t_links;

struct 			s_env
{
	t_room		*start;
	t_room		*end;
	int			nb_rooms;
	int			nb_ants;
	t_ant		**colony;
};

struct			s_room
{
	char		*id;
	int			x;
	int			y;
	t_ant		*ant;
	t_links		*links;

};

struct			s_links
{
	t_room		*linked_room;
	t_links		*prev;
	t_links		*next;
};

struct			s_ant
{
	int			n;
	t_path		*path;
};

struct			s_path
{
	int			len;
	t_room		*prev;
	t_room		*current;
	t_room		*next;
};
