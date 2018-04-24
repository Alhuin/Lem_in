/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 08:07:31 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 17:43:26 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_best_pos(t_flr *box, int i, int j, int b)
{
	int pf_y;
	int pf_x;

	pf_y = box->pf_y;
	pf_x = box->pf_x;
	if ((box->dir_x == 0 && box->dir_y == 1 && i < pf_x) ||
			(box->dir_x == 0 && box->dir_y == 2 && i > pf_x) ||
			(box->dir_x == 1 && box->dir_y == 0 && j > pf_y) ||
			(box->dir_x == 1 && box->dir_y == 1 && i <= pf_x && j > pf_y) ||
			(box->dir_x == 1 && box->dir_y == 1 && i < pf_x && j >= pf_y) ||
			(box->dir_x == 1 && box->dir_y == 2 && i < pf_x && j <= pf_y) ||
			(box->dir_x == 1 && box->dir_y == 2 && i <= pf_x && j < pf_y) ||
			(box->dir_x == 2 && box->dir_y == 0 && j < pf_y) ||
			(box->dir_x == 2 && box->dir_y == 1 && i > pf_x && j >= pf_y) ||
			(box->dir_x == 2 && box->dir_y == 1 && i >= pf_x && j > pf_y) ||
			(box->dir_x == 2 && box->dir_y == 2 && i > pf_y && j <= pf_y) ||
			(box->dir_x == 2 && box->dir_y == 2 && i >= pf_y && j < pf_y))
		if (!ft_placable_generic(box, i, j))
		{
			box->pf_x = i;
			box->pf_y = j;
			b = 1;
		}
	return (b);
}

int		ft_begin_piece(t_flr *box)
{
	int	j;
	int	i;
	int	b;

	j = 0;
	b = 0;
	while (box->piece[j] != NULL)
	{
		i = 0;
		while (box->piece[j][i] != '\0')
		{
			if (box->piece[j][i] == '*')
			{
				box->pf_x = i;
				box->pf_y = j;
				b = 1;
				break ;
			}
			i++;
		}
		if (b == 1)
			break ;
		j++;
	}
	return (b);
}

int		ft_goto(t_flr *box)
{
	int		i;
	int		j;
	int		b;

	box->pf_x = -1;
	box->pf_y = -1;
	b = ft_begin_piece(box);
	j = 0;
	b = 0;
	while (box->piece[j] != NULL)
	{
		i = 0;
		while (box->piece[j][i] != '\0')
		{
			if (box->piece[j][i] == '*')
				b = ft_best_pos(box, i, j, 0);
			i++;
		}
		j++;
	}
	if (b == 0 && !ft_placable_generic(box, box->start_x, box->start_y))
		return (0);
	else if (b == 1)
		return (0);
	return (1);
}
