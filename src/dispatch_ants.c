/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatch_ants.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 18:23:25 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 15:51:15 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		**swap_one(int **to_play, int i, int j)
{
	to_play[i][0] -= 1;
	to_play[j][0] += 1;
	return (to_play);
}

int		check_all(int **to_play)
{
	int	j;

	j = 0;
	while (to_play[j])
	{
		if (to_play[0][0] - to_play[j][0] > 1)
			return (0);
		j++;
	}
	return (1);
}

int		**check_swap_interval(int **to_play)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (to_play[j] && !check_all(to_play))
	{
		while (to_play[j] && ft_abs(to_play[j - 1][0] - to_play[j][0]) <= 1)
			j++;
		while (to_play[j] && to_play[j - 1][0] - to_play[j][0] > 1)
		{
			swap_one(to_play, j - 1, j);
			j = 1;
		}
	}
	return (to_play);
}

int		**len_of_one(t_lem *e, int **poss, int index, int **to_play)
{
	to_play[0][1] = e->nb_ants;
	to_play[0][0] = to_play[0][1] +
		ft_inttablen(e->data[e->nb_room - 1].path[poss[index][0]]);
	return (to_play);
}

int		**count_plays(int **paths, int **poss, t_lem *e, int index)
{
	int	**to_play;
	int	i;
	int len;

	i = -1;
	len = ft_inttablen(poss[index]);
	if (!(to_play = malloc(sizeof(int *) * (len + 1))))
		return (NULL);
	to_play[len] = NULL;
	while (++i < len)
		if (!(to_play[i] = malloc(sizeof(int) * 2)))
			return (NULL);
	if (len == 1)
		return (len_of_one(e, poss, index, to_play));
	i = -1;
	while (poss[index][++i] != -1)
		to_play[i][0] = ft_inttablen(paths[poss[index][i]]);
	to_play[0][0] += e->nb_ants;
	to_play = check_swap_interval(to_play);
	i = -1;
	while (++i < len)
		to_play[i][1] = to_play[i][0] - ft_inttablen(paths[poss[index][i]]);
	return (to_play);
}
