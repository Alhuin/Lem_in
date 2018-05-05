/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatch_ants.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 18:23:25 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/05 17:19:49 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*int		check_interval(int **tamere, int i)
{
	if (abs(tamere[i][0] - tamere[i + 1][0]) > 1)
		return (0);
	return (1);
}*/

int		**swap_one(int **tamere, int i, int j)
{
	tamere[i][0] -=  1;
	tamere[j][0] += 1;
/*	tamere[i][0] = (tamere[i][0] > tamere[j][0] ? tamere[i][0] - 1 : tamere[i][0] + 1);
	tamere[j][0] = (tamere[j][0] > tamere[i][0] ? tamere[j][0] - 1 : tamere[j][0] + 1);*/
	dprintf(1, "\ntamere[i][0] = %d\ntamere[j][0] = %d\n", tamere[i][0], tamere[j][0]);
	return (tamere);
}

int		**check_swap_interval(int **tamere)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (tamere[j] && tamere[i][0] - tamere[j][0] > 1)
	{
		j = 1;
		while (tamere[j] && abs(tamere[i][0] - tamere[j][0]) <= 1)
		{
			dprintf(1, "CHECK \ntamere[i][0] = %d\ntamere[j][0] = %d\n", tamere[i][0], tamere[j][0]);
			j++;
		}
		while (tamere[j] && tamere[i][0] - tamere[j][0] > 1)
			swap_one(tamere, j - 1, j);
		j = 1;
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
			if (ft_inttablen(paths[e->all_path[i][j]]) > ft_inttablen(paths[e->all_path[i][k]]))
				e->all_path = swap_path(e->all_path, i, j, k);
			j++;
		}
	}
	i = -1;
	j = -1;
	dprintf(1, "ALL_PATH SORTED\n");
	while (++i < e->nb_path)
	{
		j = -1;
		while (e->all_path[i][++j] != -1)
		{
			dprintf(1, "%d ", e->all_path[i][j]);
		}
		dprintf(1, "\n");
	}
}

int		**count_plays(int **paths, int **poss, t_lem *e, int index)
{
	int	**tamere;
	int	plays;
	int	i;
	int len;

	dprintf(1, "1 WTF?\n");
	i = -1;
	plays = 0;
	len = ft_inttablen(poss[index]);
	if (!(tamere = malloc(sizeof(int *) * (len + 1))))
		return (NULL);
	dprintf(1, "2 WTF?\n");
	tamere[len] = NULL;
	while (++i < len)
		if (!(tamere[i] = malloc(sizeof(int) * 2)))
			return (NULL);
	dprintf(1, "3 WTF?\n");
	if (len == 1)
	{
		tamere[0][1] = e->nb_ants;
		tamere[0][0] = tamere[0][1] + ft_inttablen(paths[poss[index][0]]);
		return (tamere);
	}
	dprintf(1, "4 WTF?\n");
	i = -1;
	while (poss[index][++i] != -1)
	{
	dprintf(1, "5 WTF?\n");
		tamere[i][0] = ft_inttablen(paths[poss[index][i]]);
	}
	i = 0;
	tamere[0][0] += e->nb_ants;
	plays = tamere[0][0];
	tamere = check_swap_interval(tamere);
/*	while (++i < len - 1)
	{
	dprintf(1, "6 WTF?\n");
		if (!check_interval(tamere, i))
		{
	dprintf(1, "7 WTF?\n");
			while (!check_interval(tamere, i))
				tamere = swap_one(tamere, i, i + 1);
			i = -1;
		}
	}*/
	dprintf(1, "8 WTF?\n");
	i = -1;
	while (++i < len)
	{
		dprintf(1, "\nposs = %d\ntamere[i][0] = %d\n longueur de chemin = %d\n", index, tamere[i][0], ft_inttablen(paths[poss[index][i]]));
		tamere[i][1] = tamere[i][0] - ft_inttablen(paths[poss[index][i]]);
		}
	dprintf(1, "9 WTF?\n");
	return (tamere);
}
