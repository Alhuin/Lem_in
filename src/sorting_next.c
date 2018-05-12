/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:17:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 15:54:52 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			data_to_tmp(int a, int b, t_room *tmp, t_lem *e)
{
	int i;

	i = -1;
	tmp[b].name = ft_strdup(e->data[a].name);
	if (!(tmp[b].links = malloc(sizeof(int) * e->data[a].nb_links)))
		return (-1);
	while (++i < e->data[a].nb_links)
		tmp[b].links[i] = e->data[a].links[i];
	tmp[b].room_x = e->data[a].room_x;
	tmp[b].room_y = e->data[a].room_y;
	tmp[b].nb_links = e->data[a].nb_links;
	tmp[b].dist_s = e->data[a].dist_s;
	tmp[b].dist_e = e->data[a].dist_e;
	return (0);
}

int			tmp_to_data(int a, int b, t_room *tmp, t_lem *e)
{
	int i;

	i = -1;
	e->data[b].name = ft_strdup(tmp[a].name);
	if (!(e->data[b].links = malloc(sizeof(int) * tmp[a].nb_links)))
		return (-1);
	while (++i < tmp[a].nb_links)
		e->data[b].links[i] = tmp[a].links[i];
	e->data[b].room_x = tmp[a].room_x;
	e->data[b].room_y = tmp[a].room_y;
	e->data[b].nb_links = tmp[a].nb_links;
	e->data[b].dist_s = tmp[a].dist_s;
	e->data[b].dist_e = tmp[a].dist_e;
	return (0);
}

int			**swap_path(int **poss, int i, int j, int k)
{
	int tmp;

	tmp = poss[i][j];
	poss[i][j] = poss[i][k];
	poss[i][k] = tmp;
	return (poss);
}

void		sort_all_path(t_lem *e, int **paths)
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

int			*ft_inttabjoin(int *s1, int *s2, int i)
{
	int		j;
	int		*new;

	if (s1 == NULL && s2 == NULL)
	{
		new = malloc(sizeof(int));
		new[0] = -1;
		return (new);
	}
	else if (s1 == NULL)
		return (ft_inttabdup(s2));
	else if (s2 == NULL)
		return (ft_inttabdup(s1));
	i = ft_inttablen(s1) + ft_inttablen(s2);
	if (!(new = malloc(sizeof(int) * (i + 1))))
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != -1)
		new[++j] = s1[i];
	i = -1;
	while (s2[++i] != -1)
		new[++j] = s2[i];
	new[j] = -1;
	return (new);
}
