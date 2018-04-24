#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/ft_printf.h"
# include <fcntl.h>

typedef struct	s_mat
{
	int			l;
	int			value;
	int			stone;
}				t_mat;

typedef struct s_room
{
	char		*name;
	int			room_x;
	int			room_y;
	int			*links;
	int			nb_links;
	int			dist_s;
	int			dist_e;
}				t_room;

typedef struct	s_lem
{
	int			nb_ants;
	int			nb_room;
	int			start;
	int			end;
	char		*line;
	char		*save;
	int			start_end;
	int			stop;
	int			total_nb_links;
	int			error;
	int			room;
	t_mat		**matrix;
	t_room		*data;
}				t_lem;

int				ft_check_room_name(t_lem *e, char *name, int o);
int				ft_check_room_coord(t_lem *e, int x, int y);
int				ft_init_room(char *name, t_lem *e, int x, int y);
void			ft_free_tmp(char **tmp);
char			**ft_get_room(t_lem *e);
void			ft_diese(t_lem *e);
int				ft_parse(t_lem *e);
int				ft_error(t_lem *e);
char			**ft_get_links(t_lem *e);
int				ft_init_links(t_lem *e, int i, int j);
int				make_matrice(t_lem *e);
void			bfs(t_lem *e, int ind);

#endif
