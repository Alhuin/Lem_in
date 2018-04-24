/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filling.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 14:01:20 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 18:16:17 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_putable(t_flr *box)
{
	int	sad;
	int	i;
	int	j;

	j = 0;
	sad = 101;
	while (j < box->map_y)
	{
		i = 0;
		while (i < box->map_x)
		{
			if (box->map_poss[j][i] != 0)
				sad = 0;
			i++;
		}
		j++;
	}
	return (sad);
}

void	ft_put_piece(t_flr *box, int i_max, int j_max, int j)
{
	int	i;
	int	max;

	max = 0;
	while (j < box->map_y && !(i = 0))
	{
		while (i < box->map_x)
		{
			if (ft_is_placable(box, i, j) && box->map_poss[j][i] >= max)
			{
				max = box->map_poss[j][i];
				i_max = i;
				j_max = j;
			}
			i++;
		}
		j++;
	}
	ft_printf("%i %i\n", j_max, i_max);
}

int		ft_algo2(t_flr *box)
{
	box->strat = 0;
	if (box->odd == 0)
		ft_zone_start(box);
	ft_zone_move(box);
	if (box->strat == 2)
		return (1);
	ft_start(box);
	ft_direction(box);
	box->odd++;
	if (!ft_goto(box) && ft_is_placable(box, box->ret_x, box->ret_y))
	{
		ft_printf("%i %i\n", box->ret_y, box->ret_x);
		return (0);
	}
	return (1);
}
