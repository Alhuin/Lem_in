/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nassim_tools.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 17:34:13 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 15:51:38 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int					data_sort_next(t_lem *e, int *equiv, t_room *tmp)
{
	int		k;

	k = -1;
	while (++k < e->nb_room)
	{
		if (equiv[k] == -1)
			continue ;
		if (tmp_to_data(k, k, tmp, e) == -1)
			return (-1);
		ft_strdel(&tmp[k].name);
		ft_intdel(&tmp[k].links);
	}
	free(tmp);
	return (0);
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
			i++;
		if (i == e->nb_room)
			continue ;
		if (data_to_tmp(i, k, tmp, e) == -1)
			return (-1);
		ft_strdel(&e->data[i].name);
		ft_intdel(&e->data[i].links);
	}
	if (data_sort_next(e, equiv, tmp) == -1)
		return (-1);
	return (0);
}

void				data_scan_next(t_lem *e, int *equiv, int k, int j)
{
	int		i;

	i = -1;
	while (++i < e->nb_room)
	{
		if (equiv[i] == -1)
			equiv[i] = ++k;
	}
	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
			e->data[i].links[j] = equiv[e->data[i].links[j]];
	}
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
	data_scan_next(e, equiv, k, j);
}

int					ft_sorting(t_lem *e)
{
	int i;
	int equiv[e->nb_room];

	i = -1;
	while (++i < e->nb_room)
	{
		if (i == e->end)
			equiv[i] = 0;
		else if (i == e->start)
			equiv[i] = e->nb_room - 1;
		else
			equiv[i] = -1;
	}
	data_scan(e, equiv);
	if (data_sort(e, equiv) == -1)
		return (-1);
	return (0);
}
