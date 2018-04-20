/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bresenham.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 11:52:44 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:32:23 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	first_case(t_bshm *b, t_fdf *s)
{
	b->i = 0;
	while (b->i++ <= b->ddx)
	{
		mlx_pixel_put(s->mlx_ptr, s->win_ptr, b->x1, b->y1, 0xFFFFFF);
		b->x1 += b->xincr;
		b->ex -= b->dy;
		if (b->ex < 0)
		{
			b->y1 += b->yincr;
			b->ex += b->dx;
		}
	}
}

void	second_case(t_bshm *b, t_fdf *s)
{
	b->i = 0;
	while (b->i++ <= b->ddy)
	{
		mlx_pixel_put(s->mlx_ptr, s->win_ptr, b->x1, b->y1, 0xFFFFFF);
		b->y1 += b->yincr;
		b->ey -= b->dx;
		if (b->ey < 0)
		{
			b->x1 += b->xincr;
			b->ey += b->dy;
		}
	}
}

void	third_case(t_bshm *b, t_fdf *s)
{
	b->i = 0;
	if (b->ddx == 0)
		while (b->i++ <= b->ddy)
		{
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, b->x1, b->y1, 0xFFFFFF);
			b->y1++;
		}
	else if (b->ddy == 0)
		while (b->i++ <= b->ddx)
		{
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, b->x1, b->y1, 0xFFFFFF);
			b->x1++;
		}
}

void	ft_initialize_bre(t_bshm *b)
{
	b->ex = ft_abs(b->x2 - b->x1);
	b->ey = ft_abs(b->y2 - b->y1);
	b->dx = 2 * b->ex;
	b->dy = 2 * b->ey;
	b->ddx = b->ex;
	b->ddy = b->ey;
	b->xincr = 1;
	b->yincr = 1;
}

void	ft_bresenham(t_fdf *s, struct s_pos *map1, struct s_pos *map2)
{
	t_bshm	*b;

	b = malloc(sizeof(t_bshm));
	b->x1 = map1->x_f;
	b->y1 = map1->y_f;
	b->x2 = map2->x_f;
	b->y2 = map2->y_f;
	ft_initialize_bre(b);
	if (b->x1 > b->x2)
		b->xincr = -1;
	if (b->y1 > b->y2)
		b->yincr = -1;
	if (b->ddx > b->ddy)
		first_case(b, s);
	else if (b->ddx < b->ddy)
		second_case(b, s);
	else if (b->ddx == b->ddy)
		third_case(b, s);
	free(b);
}
