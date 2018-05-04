/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lemin.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:15:42 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 17:08:51 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/ft_printf.h"
# include <fcntl.h>

struct s_forest;

typedef struct	s_mat
{
	int			l;
	int			value;
	int			stone;
}				t_mat;

typedef struct	s_room
{
	char		*name;
	int			room_x;
	int			room_y;
	int			*links;
	int			nb_links;
	int			dist_s;
	int			dist_e;
	int			**path;
	int			nb_path;
}				t_room;

typedef struct	s_forest
{
	struct s_room		*room;
	struct s_forest		*parent;
	struct s_forest		**subtree;
}				t_forest;

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
	int			**sorted;
	int			**matrix;
	int			**all_path;
	int			nb_path;
	t_room		*data;
}				t_lem;

int				init_env(t_lem **e);
int				ft_check_room_name(t_lem *e, char *name, int o);
int				ft_check_room_coord(t_lem *e, int x, int y);
int				ft_init_room(char *name, t_lem *e, int x, int y);
void			ft_free_tmp(char **tmp);
char			**ft_get_room(t_lem *e);
void			ft_diese(t_lem *e);
int				ft_parse(t_lem *e, char **t);
int				ft_error(t_lem *e);
char			**ft_get_links(t_lem *e);
int				ft_init_links(t_lem *e, int i, int j);
int				make_matrice(t_lem *e);
int				algo_main(t_lem *e);
void			free_env(t_lem **e);
void			ft_intdel(int **as);
int				data_sort(t_lem *e, int *equiv);
void			data_scan(t_lem *e, int *equiv);
int				ft_inttablen(int *tab);
int				algo_next(t_lem *e);

//-----------------------------------------------------------------------------
//								A DEGAGER									   
//-----------------------------------------------------------------------------
void			swap_matrix(t_lem *e, int a, int b);
void			print_matrix(t_lem *e);
void			print_equiv(t_lem *e, int *equiv);
void			print_datalinks(t_lem *e);
int				sort_matrix(t_lem *e);
int				make_matricei_suit(t_lem *e);
int				make_matrice(t_lem *e);
void			ft_print_allpath(t_lem *e);
void			ft_print_path(t_lem *e, int j);
#endif
