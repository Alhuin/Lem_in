/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:51:16 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 14:09:18 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			ft_check_room_name(t_lem *e, char *name, int o)
{
	int		i;
	int		eq;

	eq = 0;
	i = 0;
	if (!e->data)
		return (0);
	if (name[0] == 'L')
		return (-1);
	//dprintf(2, "c'est la zob\n");
	while (i < e->nb_room)
	{
		if (ft_strcmp(name, e->data[i].name) == 0)
			eq++;
	//	dprintf(2, "voici les comparaison : %s %s\n", name, e->data[i].name);
		i++;
	}
	if (o == 1 && eq != 0)
	{
	//	dprintf(2, "o == 1\neq = %d\n", eq);
		return (-1);
	}
	if (o == 2 && eq != 1)
	{
		return (-1);
	}
	return (0);
}

int			ft_check_room_coord(t_lem *e, int x, int y)
{
	int		i;

	i = 0;
	if (!e->data)
		return (0);
	while (i < e->nb_room)
	{
		if (x == e->data[i].room_x && y == e->data[i].room_y)
			return (-1);
		i++;
	}
	return (0);
}

int			ft_init_room(char *name, t_lem *e, int x, int y)
{
	e->nb_room++;
	if (!e->data)
	{
		if (!(e->data = malloc(sizeof(t_room))))
			return (-1);
	}
	else
	{
		if (!(e->data = ft_realloc(e->data, sizeof(t_room) * (e->nb_room - 1),
						sizeof(t_room) * e->nb_room)))
			return (-1);
	}
	e->data[e->nb_room - 1].name = ft_strdup(name);
	e->data[e->nb_room - 1].room_x = x;
	e->data[e->nb_room - 1].room_y = y;
	e->data[e->nb_room - 1].links = NULL;
	e->data[e->nb_room - 1].nb_links = 0;
	e->data[e->nb_room - 1].path = NULL;
	e->data[e->nb_room - 1].nb_path = 0;
	e->data[e->nb_room - 1].ant = 0;
	e->data[e->nb_room - 1].floor = -1;
	e->data[e->nb_room - 1].dist_s = (e->start_end == 1 ? 0 : -1);
	e->data[e->nb_room - 1].dist_e = (e->start_end == 2 ? 0 : -1);
	if (e->start_end == 1)
		e->start = e->nb_room - 1;
	if (e->start_end == 2)
		e->end = e->nb_room - 1;
	e->start_end = 0;
	return (0);
}

void		ft_free_tmp(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
}

char		**ft_get_room(t_lem *e)
{
	int		i;
	char	**t;

	i = 0;
	if (!(t = ft_strsplit(e->line, ' ')))
		return (NULL);
	while (t[++i])
	{
		if (!ft_str_is_num(t[i]))
			e->error = 1;
	}
	if (i != 3)
		e->error = 1;
	if (e->error == 1)
	{
		ft_free_tmp(t);
		e->error = 0;
		return (NULL);
	}
	return (t);
}
