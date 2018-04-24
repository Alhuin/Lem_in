/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_box_poss.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 14:01:45 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 14:40:53 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		ft_zero(t_flr **box, int j)
{
	int	n;

	n = 0;
	while (n < (*box)->map_x)
		(*box)->map_poss[j][n++] = 0;
}

static t_flr	*init_poss(t_flr *box)
{
	int	i;
	int	j;

	j = 0;
/*	while (j < box->map_y)
	{
		dprintf(2, "{%s}\n", box->map[j]);
		j++;
	}
	j = 0;
	while (j < box->piece_y)
	{
		dprintf(2, "{%s}\n", box->piece[j]);
		j++;
	}
	j = 0;*/
	if (!(box->map_poss = (int**)malloc(sizeof(int*) * box->map_y)))
		return (NULL);
	while (j < box->map_y)
	{
		i = 0;
		if (!(box->map_poss[j] = (int*)malloc(sizeof(int) * box->map_x)))
			return (NULL);
		ft_zero(&box, j);
		while (i < box->map_x)
		{
			if (ft_is_placable(box, i, j) == 1)
				box->map_poss[j][i] = ft_nbr_poss(box, i, j);
			i++;
		}
		j++;
	}
	j = 0;
	/*while (j < box->map_y)
	{
		i = 0;
		while (i < box->map_x)
		{
			dprintf(2, "%d ", box->map_poss[j][i]);
			i++;
		}
		dprintf(2, "\n");
		j++;
	}*/
	return (box);
}

t_flr			*init_box(t_flr *box, int stop)
{
	if (!stop)
	{
		if (!(box = (t_flr*)malloc(sizeof(t_flr))))
			return (NULL);
		get_next_line(0, &box->line);
		if (ft_strstr(box->line, "p1") && ft_strstr(box->line, "nbettach"))
		{
			box->me = "Oo";
			box->him = "Xx";
		}
		else if (ft_strstr(box->line, "p2") &&
			ft_strstr(box->line, "nbettach"))
		{
			box->me = "Xx";
			box->him = "Oo";
		}
		ft_strdel(&box->line);
		box->odd = 0;
		box->dodo = 0;
	}
	box->strat = 0;
//	dprintf(2, "avant le big_loop\n");
	big_loop(box);
//	dprintf(2, "apres le big_loop\n");
//	dprintf(2, "avant l'init_poss\n");
	box = init_poss(box);
//	dprintf(2, "apres l'init_poss\n");
	return (box);
}

t_flr			*freeing_box(t_flr *box, int all)
{
	int	j;

	j = 0;
	while (j < box->piece_y)
		free(box->piece[j++]);
	free(box->piece);
	j = 0;
	while (j < box->map_y)
		free(box->map[j++]);
	free(box->map);
	j = 0;
	while (j < box->map_y)
		free(box->map_poss[j++]);
	free(box->map_poss);
	if (all == 1)
	{
		free(box);
		box = NULL;
	}
	return (box);
}
