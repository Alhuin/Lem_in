#ifndef LEMIN_H
# define FILLER_H

# include "libft/ft_printf.h"
# include <fcntl.h>

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
	char		*line;
	char		*save;
	char		**equiv;
	int			start_end;
	int			stop;
	int			total_nb_links;
	int			error;
	t_room		*data;
}				t_lem;



#endif
