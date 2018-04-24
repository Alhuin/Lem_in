/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools_next.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 07:54:16 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:15:41 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

float	ft_intervalle(int x, int y, int i, int j)
{
	float	nbr;

	nbr = ft_pow(i - x, 2) + ft_pow(j - y, 2);
	return (ft_sqrt(nbr));
}

void	ft_direction(t_flr *box)
{
	if (box->end_x - box->start_x > 0)
		box->dir_x = 1;
	else if (box->end_x - box->start_x == 0)
		box->dir_x = 0;
	else
		box->dir_x = 2;
	if (box->end_y - box->start_y < 0)
		box->dir_y = 1;
	else if (box->end_y - box->start_y == 0)
		box->dir_y = 0;
	else
		box->dir_y = 2;
}

int		ft_placable_generic(t_flr *box, int i, int j)
{
	int	x;
	int	y;

	j = -1;
	y = box->start_y;
	while (box->piece[++j] != NULL)
	{
		i = -1;
		x = box->start_x;
		while (box->piece[j][++i] != '\0')
		{
			if (box->piece[j][i] == '*' && box->map[y][x] != '.')
			{
				if (!(ft_strchr(box->me, box->map[y][x]))
					&& (y != box->start_y) && (x != box->start_x))
					return (1);
			}
			x++;
		}
		y++;
	}
	box->ret_x = box->start_x;
	box->ret_y = box->start_y;
	return (0);
}

void	ft_zm_strat(t_flr *box, int a, int b)
{
	int	y;
	int	x;

	y = 0;
	while (box->map[y] != NULL)
	{
		x = 0;
		while (box->map[y][x] != '\0')
		{
			if ((box->map[y][x] != '.') && (x == a) && (y == b))
				box->strat++;
			x++;
		}
		y++;
	}
}

void	ft_zm_attrib(t_flr *box, int a, int b)
{
	ft_zm_strat(box, a, b);
	if (box->strat == 1)
	{
		box->odd++;
		ft_zone_move(box);
	}
	else if (box->strat == 0)
	{
		box->end_x = a;
		box->end_y = b;
	}
	else if (box->strat == 2)
		box->dodo = 1;
}
