/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 14:02:31 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 14:31:48 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/ft_printf.h"

typedef struct	s_flr
{
	char	**map;
	char	**piece;
	int		**map_poss;
	char	*line;
	char	*me;
	char	*him;
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;

	int		start_x;
	int		start_y;
	int		end_x;
	int		end_y;
	int		dir_x;
	int		dir_y;

	int		ret_x;
	int		ret_y;

	int		odd;
	int		zone_me;
	int		zone_him;
	int		strat;
	int		dodo;

	int		pf_x;
	int		pf_y;


}				t_flr;

t_flr			*init_box(t_flr *box, int stop);
t_flr			*freeing_box(t_flr *box, int all);
int				ft_is_placable(t_flr *box, int i, int j);
int				ft_nbr_poss(t_flr *box, int i, int j);
int				big_loop(t_flr *box);
void			ft_put_piece(t_flr *box, int i_max, int j_max, int j);
int				ft_putable(t_flr *box);
int				ft_algo2(t_flr *box);
float			ft_sqrt(float number);
void			ft_zone_move(t_flr *box);
void			ft_zm_attrib(t_flr *box, int a, int b);
int				ft_goto(t_flr *box);
int				ft_placable_generic(t_flr  *box,int i,int j);
float			ft_intervalle(int x, int y, int i, int j);
void			ft_direction(t_flr *box);
void			ft_start(t_flr *box);
void			ft_zone_start(t_flr *box);
#endif
