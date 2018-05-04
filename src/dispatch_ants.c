/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatch_ants.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 18:23:25 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 19:58:32 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_interval(int *tamere, int i, int **poss)
{
	if (abs(tamere[i] - tamere[i + 1]) > 1)
		return (0);
	return (1);
}

int		*swap_one(int *tamere, int i, int j)
{
	tamere[i] -= 1;
	tamere[j] += 1;
	return (tamere);
}

int		count_plays(int **paths, int **poss, t_lem *e, int index)
{
	int	*tamere;
	int	plays;
	int	i;
	int len;

	len = ft_inttablen(poss[index]);
	if (!(tamere = malloc(sizeof(int) * len)))
		return (0);
	i = -1;
	while (poss[index][++i] != -1)
		tamere[i] = ft_inttablen(paths[poss[index][i]]);
	i = -1;
	tamere[0] += e->nb_ants;
	plays = tamere[0];
	while (++i < len)
	{
		if (!check_interval(tamere, i, poss))
		{
			while (!check_interval(tamere, i, poss))
				swap_one(tamere, i, i + 1);
			i = -1;
		}
	}
	i = -1;
	while (++i < len)
		if (plays < tamere[i])
			plays = tamere[i];
	return (plays);
}
