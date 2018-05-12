/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:51:16 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 12:27:24 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			ft_check_room_name(t_lem *e, char *name, int o)
{
	int		i;
	int		eq;

	eq = 0;
	i = -1;
	if (!e->data)
		return (0);
	if (name[0] == 'L')
		return (-1);
	if (ft_strchr(name, '-'))
		return (-1);
	while (++i < e->nb_room)
		if (ft_strcmp(name, e->data[i].name) == 0)
			eq++;
	if (o == 1 && eq != 0)
		return (-1);
	if (o == 2 && eq != 1)
		return (-1);
	return (0);
}

int			ft_check_room_coord(t_lem *e, int x, int y)
{
	int		i;

	i = -1;
	if (!e->data)
		return (0);
	while (++i < e->nb_room)
		if (x == e->data[i].room_x && y == e->data[i].room_y)
			return (-1);
	return (0);
}

void		ft_init_room_next(t_lem *e, int x, int y, char *name)
{
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
	ft_init_room_next(e, x, y, name);
	if (e->start_end == 1)
		e->start = e->nb_room - 1;
	if (e->start_end == 2)
		e->end = e->nb_room - 1;
	e->start_end = 0;
	return (0);
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
