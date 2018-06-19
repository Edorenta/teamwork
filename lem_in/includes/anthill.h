#ifndef ANTHILL_H
# define ANTHILL_H

# define R1 (env->first_parsed_room)
# define R2 (env->last_parsed_room)
# define L1 (env->first_parsed_link)
# define L2 (env->last_parsed_link)

typedef struct s_path			t_path;
typedef struct s_room			t_room;
typedef struct s_ant			t_ant;
typedef struct s_env			t_env;
typedef struct s_link			t_link;
typedef struct s_lines			t_lines;
typedef struct s_parsed_room	t_parsed_room;
typedef struct s_parsed_link	t_parsed_link;


struct 			s_env
{
	t_room			*start;
	t_room			*end;
	t_path			*fastway;
	t_lines			*first_line;
	t_parsed_room	*first_parsed_room;
	t_parsed_room	*last_parsed_room;
	t_parsed_link	*first_parsed_link;
	t_parsed_link	*last_parsed_link;
	char			opt;
	int				nb_rooms;
	int				nb_ants;
	t_ant			**colony;
};

struct			s_room
{
	char			id[256];
	int				x;
	int				y;
	t_ant			*ant;
	t_link			*link;
};

struct			s_parsed_room
{
	t_room			*room;
	t_parsed_room	*prev;
	t_parsed_room	*next;
};

struct			s_link
{
	t_room			*room;
	t_link			*prev;
	t_link			*next;
};

struct			s_lines
{
	char			*txt;
	t_lines			*next;
};

struct			s_parsed_link
{
	t_room			*room1;
	t_room			*room2;
	t_parsed_link	*prev;
	t_parsed_link	*next;
};

struct			s_ant
{
	int				n;
	t_path			*path;
};

struct			s_path
{
	t_path			*prev;
	t_room			*room;
	t_path			*next;
};

#endif
