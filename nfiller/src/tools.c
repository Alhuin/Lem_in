/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tools.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 14:02:08 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 14:02:10 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

int			ft_is_placable(t_flr *box, int i, int j)
{
	int	k;
	int	l;
	int	sup;

	sup = 0;
	l = 0;
	while (l < box->piece_y)
	{
		k = 0;
		while (k < box->piece_x)
		{
			if (box->piece[l][k] == '*' && (j + l >= box->map_y || i + k >=
				box->map_x || ft_strchr(box->him, box->map[j + l][i + k])))
				return (0);
			else if (box->piece[l][k] == '*' &&
				ft_strchr(box->me, box->map[j + l][i + k]))
				sup++;
			k++;
		}
		l++;
	}
	if (sup == 1)
		return (1);
	else
		return (0);
}

static int	ft_nbr_poss1(t_flr *box, int i, int j)
{
	int	ii;
	int	jj;
	int	nb;

	nb = 0;
	jj = -1;
	while (jj < 2 && (ii = -1))
	{
		while (ii < 2)
		{
			if (ii++ == 0 && jj == 0)
				;
			else if (j + jj < 0 || i + ii - 1 < 0 || j + jj >= box->map_y ||
				i + ii - 1 >= box->map_x || (j + jj >= 0 && i + ii - 1 >= 0 &&
				j + jj < box->map_y && i + ii - 1 < box->map_x &&
				ft_strchr(box->me, box->map[j + jj][i + ii - 1])))
				nb++;
			else if (j + jj >= 0 && i + ii - 1 >= 0 && j + jj < box->map_y &&
				i + ii - 1 < box->map_x &&
				ft_strchr(box->him, box->map[j + jj][i + ii - 1]))
				nb = nb + 1000;
		}
		jj++;
	}
	return (nb);
}

int			ft_nbr_poss(t_flr *box, int i, int j)
{
	int	nb;
	int	k;
	int	l;

	l = 0;
	nb = 0;
	while (l < box->piece_y && j + l < box->map_y)
	{
		k = 0;
		while (k < box->piece_x && i + k < box->map_x)
		{
			if (box->piece[l][k] == '*')
				nb += ft_nbr_poss1(box, i + k, j + l);
			k++;
		}
		l++;
	}
	return (nb);
}
