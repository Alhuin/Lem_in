/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 06:51:12 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:32:25 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "libft/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include "keys.h"

# define WIN_X		1000
# define WIN_Y		1000

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_pos	**map;
	int				x_max;
	int				y_max;
	int				error;
	int				zoom;
	int				move_x;
	int				move_y;
	int				angle_y;
	int				angle_x;
}					t_fdf;

typedef struct		s_bshm
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				ex;
	int				ey;
	int				dx;
	int				dy;
	int				ddx;
	int				ddy;
	int				i;
	int				xincr;
	int				yincr;
}					t_bshm;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
	int				x_f;
	int				y_f;
}					t_pos;

void				ft_bresenham(t_fdf *s, struct s_pos *map1,
									struct s_pos *map2);
void				ft_reader(t_fdf *s, char *file_name);
void				ft_parse_map(t_fdf *s, char *line, int i);
void				ft_calc_final(t_fdf *s);
void				ft_free_fdf(t_fdf *s);

#endif
