/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatch_ants.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 18:23:25 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 12:40:49 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		**swap_one(int **tamere, int i, int j)
{
	tamere[i][0] -= 1;
	tamere[j][0] += 1;
	return (tamere);
}

int		check_all(int **tamere)
{
	int	j;

	j = 0;
	while (tamere[j])
	{
		if (tamere[0][0] - tamere[j][0] > 1)
			return (0);
		j++;
	}
	return (1);
}

int		**check_swap_interval(int **tamere)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tamere[j] && !check_all(tamere))
	{
		while (tamere[j] && ft_abs(tamere[j - 1][0] - tamere[j][0]) <= 1)
			j++;
		while (tamere[j] && tamere[j - 1][0] - tamere[j][0] > 1)
		{
			swap_one(tamere, j - 1, j);
			j = 1;
		}
	}
	return (tamere);
}

int		**swap_path(int **poss, int i, int j, int k)
{
	int tmp;

	tmp = poss[i][j];
	poss[i][j] = poss[i][k];
	poss[i][k] = tmp;
	return (poss);
}

void	sort_all_path(t_lem *e, int **paths)
{
	int i;
	int j;
	int k;

	k = 0;
	i = -1;
	while (++i < e->nb_path)
	{
		j = 0;
		while (e->all_path[i][j + 1] != -1)
		{
			k = j + 1;
			if (ft_inttablen(paths[e->all_path[i][j]]) >
					ft_inttablen(paths[e->all_path[i][k]]))
				e->all_path = swap_path(e->all_path, i, j, k);
			j++;
		}
	}
}

int		**count_plays(int **paths, int **poss, t_lem *e, int index)
{
	int	**tamere;
	int	plays;
	int	i;
	int len;

	i = -1;
	plays = 0;
	len = ft_inttablen(poss[index]);
	if (!(tamere = malloc(sizeof(int *) * (len + 1))))
		return (NULL);
	tamere[len] = NULL;
	while (++i < len)
		if (!(tamere[i] = malloc(sizeof(int) * 2)))
			return (NULL);
	if (len == 1)
	{
		tamere[0][1] = e->nb_ants;
		tamere[0][0] = tamere[0][1] + ft_inttablen(paths[poss[index][0]]);
		return (tamere);
	}
	i = -1;
	while (poss[index][++i] != -1)
	{
		tamere[i][0] = ft_inttablen(paths[poss[index][i]]);
	}
	i = 0;
	tamere[0][0] += e->nb_ants;
	plays = tamere[0][0];
	tamere = check_swap_interval(tamere);
	i = -1;
	while (++i < len)
		tamere[i][1] = tamere[i][0] - ft_inttablen(paths[poss[index][i]]);
	return (tamere);
}
