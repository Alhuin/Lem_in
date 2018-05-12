/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:16:52 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 10:59:02 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		*ft_inttabadd(int *s1, int k)
{
	int		*new;
	int		i;
	int		j;
	int		len;

	len = ft_inttablen(s1);
	if (!(new = malloc(sizeof(int) * (len + 2))))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != -1)
		new[j++] = s1[i];
	new[j++] = k;
	new[j] = -1;
	ft_intdel(&s1);
	return (new);
}

int		path_manage(t_lem *e, int i, int j, int y)
{
	if (e->data[j].path == NULL && e->data[i].nb_path > 1)
	{
		if (!(e->data[j].path = malloc(sizeof(int*) * e->data[i].nb_path)))
			return (-1);
		e->data[j].nb_path += e->data[i].nb_path;
		while (++y < e->data[i].nb_path)
			e->data[j].path[y] = NULL;
		e->data[j].nb_path = e->data[i].nb_path;
	}
	else if (e->data[j].path == NULL)
	{
		if (!(e->data[j].path = malloc(sizeof(int*))))
			return (-1);
		e->data[j].nb_path++;
		e->data[j].path[0] = NULL;
	}
	else
	{
		if (!(e->data[j].path = ft_realloc(e->data[j].path, sizeof(int*) *
						e->data[j].nb_path, sizeof(int*) * (e->data[j].nb_path
						+ e->data[i].nb_path))))
			return (-1);
		e->data[j].nb_path += e->data[i].nb_path;
	}
	return (0);
}

int		path_copy(t_lem *e, int i, int j, int l)
{
	int		k;

	if (i == 0)
	{
		if (!(e->data[j].path[0] = malloc(sizeof(int) * 2)))
			return (-1);
		e->data[j].path[0][0] = i;
		e->data[j].path[0][1] = -1;
		return (0);
	}
	if (e->data[j].nb_path == 1 && e->data[i].nb_path > e->data[j].nb_path)
		k = 0;
	else
		k = e->data[j].nb_path - e->data[i].nb_path;
	while (k < e->data[j].nb_path)
	{
		if (!(e->data[j].path[k] = ft_inttabjoin(e->data[i].path[l],
				e->data[j].path[k])))
			return (-1);
		if (!(e->data[j].path[k] = ft_inttabadd(e->data[j].path[k], i)))
			return (-1);
		k++;
		l++;
	}
	return (0);
}

void	make_floor(t_lem *e)
{
	int i;
	int j;
	int f;

	f = -1;
	i = -1;
	while (++i < e->nb_room - 1)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
		{
			if (i == 0)
				e->data[i].floor = 0;
			if (e->data[e->data[i].links[j]].floor == -1)
			{
				e->data[e->data[i].links[j]].floor = e->data[i].floor + 1;
				if (f < e->data[e->data[i].links[j]].floor)
					f = e->data[e->data[i].links[j]].floor;
			}
		}
	}
	e->data[e->nb_room - 1].floor = f + 1;
}

int		algo_main(t_lem *e)
{
	int		i;
	int		j;

	make_floor(e);
	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
		{
			if (e->data[i].floor <= e->data[e->data[i].links[j]].floor)
			{
				if (path_manage(e, i, e->data[i].links[j], -1))
					return (-1);
				if (path_copy(e, i, e->data[i].links[j], 0))
					return (-1);
			}
		}
	}
	if (!e->data[i - 1].path[0] || !e->data[i - 1].nb_path)
		return (-1);
	return (0);
}
