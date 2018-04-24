/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_start_aglo.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 07:40:09 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 14:01:34 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_choose_zone(t_flr *box, int x, int y)
{
	if (ft_strchr(box->me, box->map[y][x]))
	{
		if (x < (box->map_x / 2) && y < (box->map_y / 2))
			box->zone_me = 1;
		else if (x >= (box->map_x / 2) && y < (box->map_y / 2))
			box->zone_me = 2;
		else if (x < (box->map_x / 2) && y >= (box->map_y / 2))
			box->zone_me = 3;
		else if (x >= (box->map_x / 2) && y >= (box->map_y / 2))
			box->zone_me = 4;
	}
	if (ft_strchr(box->him, box->map[y][x]))
	{
		if (x < (box->map_x / 2) && y < (box->map_y / 2))
			box->zone_him = 1;
		else if (x >= (box->map_x / 2) && y < (box->map_y / 2))
			box->zone_him = 2;
		else if (x < (box->map_x / 2) && y >= (box->map_y / 2))
			box->zone_him = 3;
		else if (x >= (box->map_x / 2) && y >= (box->map_y / 2))
			box->zone_him = 4;
	}
}

void	ft_zone_start(t_flr *box)
{
	int x;
	int y;

	y = 0;
	while (box->map[y] != NULL)
	{
		x = 0;
		while (box->map[y][x] != '\0')
		{
			ft_choose_zone(box, x, y);
			x++;
		}
		y++;
	}
}

void	ft_start(t_flr *box)
{
	int		y;
	int		x;
	float	inter;
	int		f;

	y = -1;
	f = 0;
	inter = 999999999;
	while (++y < box->map_y)
	{
		x = -1;
		while (++x < box->map_x)
		{
			if ((box->map_poss[y][x] > 0)
					&& ((ft_intervalle(x, y, box->end_x, box->end_y) < inter)))
			{
				box->start_x = x;
				box->start_y = y;
				inter = ft_intervalle(box->start_x, box->start_y,
						box->end_x, box->end_y);
				f++;
			}
		}
	}
}
