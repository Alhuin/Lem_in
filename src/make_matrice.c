/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:17:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 18:37:22 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void			data_to_tmp(int a, int b, t_room *tmp, t_lem *e)
{
	int i;

	i = -1;
	tmp[b].name = ft_strdup(e->data[a].name);
	tmp[b].links = malloc(sizeof(int) * e->data[a].nb_links);
	while (++i < e->data[a].nb_links)
		tmp[b].links[i] = e->data[a].links[i];
	tmp[b].room_x = e->data[a].room_x;
	tmp[b].room_y = e->data[a].room_y;
	tmp[b].nb_links = e->data[a].nb_links;
	tmp[b].dist_s = e->data[a].dist_s;
	tmp[b].dist_e = e->data[a].dist_e;
}

static void			tmp_to_data(int a, int b, t_room *tmp, t_lem *e)
{
	int i;

	i = -1;
	e->data[b].name = ft_strdup(tmp[a].name);
	e->data[b].links = malloc(sizeof(int) * tmp[a].nb_links);
	while (++i < tmp[a].nb_links)
		e->data[b].links[i] = tmp[a].links[i];
	e->data[b].room_x = tmp[a].room_x;
	e->data[b].room_y = tmp[a].room_y;
	e->data[b].nb_links = tmp[a].nb_links;
	e->data[b].dist_s = tmp[a].dist_s;
	e->data[b].dist_e = tmp[a].dist_e;
}

int					data_sort(t_lem *e, int *equiv)
{
	t_room	*tmp;
	int		i;
	int		k;

	k = -1;
	if (!(tmp = malloc(sizeof(t_room) * e->nb_room)))
		return (-1);
	while (++k < e->nb_room)
	{
		i = 0;
		while (i < e->nb_room && equiv[i] != k)
//		{
//			dprintf(1, "swap data[%d] & data[%d]\n", i, k);
			i++;
//		}
		if (i == e->nb_room)
			continue ;
		data_to_tmp(i, k, tmp, e);
		ft_strdel(&e->data[i].name);
		ft_intdel(&e->data[i].links);
	}
	k = -1;
	while (++k < e->nb_room)
	{
//		dprintf(1, "k = %d\n", k);
		if (equiv[k] == -1)
			continue ;
		tmp_to_data(k, k, tmp, e);
		ft_strdel(&tmp[k].name);
		ft_intdel(&tmp[k].links);
	}
	free(tmp);
	return (0);
}

void				data_scan(t_lem *e, int *equiv)
{
	int i;
	int k;
	int j;
	int tour;

	k = 0;
	tour = -1;
	while (++tour < e->nb_room)
	{
		i = -1;
		while (++i < e->nb_room)
		{
			if (equiv[i] == tour)
			{
				j = -1;
				while (++j < e->data[i].nb_links)
					if (equiv[e->data[i].links[j]] == -1)
						equiv[e->data[i].links[j]] = ++k;
			}
		}
	}
	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
			e->data[i].links[j] = equiv[e->data[i].links[j]];
	}
	i = -1;
	while (++i < e->nb_room)
	{
		if (equiv[i] == - 1)
			equiv[i] = ++k;
	}
}
