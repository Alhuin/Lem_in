/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:16:52 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 16:58:09 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_inttab(int *s1)
{
	int i;

	i = -1;
	while (s1[++i] != -1)
		printf("%d ", s1[i]);
	printf("\n");
}

int		ft_inttablen(int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int		*ft_inttabdup(int *s1)
{
	int		*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	k = ft_inttablen(s1);
	if (!(s2 = malloc(sizeof(int) * (k + 1))))
		return (NULL);
	s2[k] = -1;
	while (s1[i] != -1)
		s2[j++] = s1[i++];
	return (s2);
}

int		*ft_inttabjoin(int *s1, int *s2)
{
	int		i;
	int		j;
	int		k;
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
	k = ft_inttablen(s1) + ft_inttablen(s2);
	new = malloc(sizeof(int) * (k + 1));
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

int		*ft_inttabadd(int *s1, int k)
{
	int		*new;
	int		i;
	int		j;
	int		len;

	len = ft_inttablen(s1);
//	printf("len s1 = %d\n", len);
	new = malloc(sizeof(int) * (len + 2));
	i = -1;
	j = 0;
	while (s1[++i] != -1)
		new[j++] = s1[i];
	new[j++] = k;
	new[j] = -1;
	free(s1);
	return (new);
}

int		path_manage(t_lem *e, int i, int j)
{
	int		y;

	if (e->data[j].path == NULL && e->data[i].nb_path > 1)
	{
		if (!(e->data[j].path = malloc(sizeof(int*) * e->data[i].nb_path)))
			return (-1);
		e->data[j].nb_path += e->data[i].nb_path;
		y = -1;
		while (++y <  e->data[i].nb_path)
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
		if (!(e->data[j].path = ft_realloc(e->data[j].path, sizeof(int*) * e->data[j].nb_path,
						sizeof(int*) * (e->data[j].nb_path + e->data[i].nb_path))))
			return (-1);
		e->data[j].nb_path += e->data[i].nb_path;
	}
	return (0);
}

int		path_copy(t_lem *e, int i, int j)
{
	int		k;
	int		l;

	if (i == 0)//e->data[i].path == NULL)
	{
//		dprintf(2, "[  i =   %d]\n", i);
		e->data[j].path[0] = malloc(sizeof(int) * 2);
		e->data[j].path[0][0] = i;
		e->data[j].path[0][1] = -1;
		return (0);
	}
	if (e->data[j].nb_path == 1 && e->data[i].nb_path > e->data[j].nb_path)
		k = 0;
	else
		k = e->data[j].nb_path - e->data[i].nb_path;
	l = 0;
	while (k < e->data[j].nb_path)
	{
		e->data[j].path[k] = ft_inttabjoin(e->data[i].path[l], e->data[j].path[k]);
		e->data[j].path[k] = ft_inttabadd(e->data[j].path[k], i);
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
				if (f <  e->data[e->data[i].links[j]].floor)
					f = e->data[e->data[i].links[j]].floor;
			}
		}
	}
	e->data[e->nb_room - 1].floor = f + 1;
//	i = -1;
//	dprintf(1, "\nPRINT FLOORS\n");
//	while (++i < e->nb_room)
//		dprintf(1, "room %s (data[%d]) at floor %d\n", e->data[i].name, i, e->data[i].floor);
}

int		update_path(t_lem *e, int i)
{
	int j;

	j = -1;
	while (++j < e->data[i].nb_links)
	{
		if (e->data[i].floor <= e->data[e->data[i].links[j]].floor)
		{
			if (path_manage(e, i, e->data[i].links[j]))
				return (-1);
			if (path_copy(e, i, e->data[i].links[j]))
				return (-1);
		//	ft_print_path(e, e->data[i].links[j], i);
		}
	}
	return (0);
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
				if (path_manage(e, i, e->data[i].links[j]))
					return (-1);
				if (path_copy(e, i, e->data[i].links[j]))
					return (-1);
			//	ft_print_path(e, e->data[i].links[j], i);
				if (e->data[i].floor == e->data[e->data[i].links[j]].floor && e->data[i].links[j] < i)
					if (update_path(e, e->data[i].links[j]) == -1)
						return (-1);
			}
		}
	}
	if (!e->data[i - 1].path[0] || !e->data[i - 1].nb_path)
		return (-1);
	//dprintf(1, "\nNB TOTAL PATH: %d\n", e->data[i - 1].nb_path);
	return (0);
}
