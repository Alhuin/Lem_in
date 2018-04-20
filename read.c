/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:51:16 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 13:37:27 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lemin.h"

int			ft_check_room_name(t_lem *e, char *name)
{
	int		i;

	i = 0;
	if (!e->data)
		return (0);
	while (i < e->nb_room)
	{
		if (ft_strcmp(name, e->data[i].name) == 0)
			return (-1);
		i++;
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

int			ft_init_room(char **tmp, t_lem *e, int x, int y)
{
	e->nb_room++;
	if (!e->data)
	{
		if (!(e->data = malloc(sizeof(t_room))))
			return (-1);
	}
	else
	{
		if (!(e->data = ft_realloc(e->data, sizeof(t_room) * (e->nb_room -1),
						sizeof(t_room) * e->nb_room)))
			return (-1);
	}
	e->data[e->nb_room -1].name = ft_strdup(tmp[0]);
	e->data[e->nb_room -1].room_x = x;
	e->data[e->nb_room -1].room_y = y;
	e->data[e->nb_room -1].links = NULL;
	e->data[e->nb_room -1].nb_links = 0;
	if (e->start_end == 1)
		e->data[e->nb_room -1].dist_s = 0;
	else
		e->data[e->nb_room -1].dist_s = -1;
	if (e->start_end == 2)
		e->data[e->nb_room -1].dist_e = 0;
	else
		e->data[e->nb_room -1].dist_e = -1;
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

int			ft_get_room(t_lem *e)
{
	int		i;
	char	**tmp;
	int		err;
	t_room	*room;

	room = NULL;
	i = 0;
	err = 0;
	if (!(tmp = ft_strsplit(e->line, ' ')))
		return (-1);
	if (ft_check_room_name(e, tmp[0]) == -1)
		err = 1;
	while (tmp[i])
	{
		if (!ft_str_is_num(tmp[i]))
			err = 1;
		i++;
	}
	if (i != 3 || ft_check_room_coord(e, ft_atoi(tmp[1]),
				ft_atoi(tmp[2]) == -1))
		err = 1;
	if (err == 1)
	{
		ft_free_tmp(tmp);
		return (-1);
	}
	if (ft_init_room(tmp, e, ft_atoi(tmp[1]),
				ft_atoi(tmp[2]) == -1))
		err = 1;
	ft_free_tmp(tmp);
	return (err == 1 ? -1 : 0);
}

void		ft_diese(t_lem *e)
{
	if (!ft_strcmp(e->line, "##start"))
		e->start_end = 1;
	else if (!ft_strcmp(e->line, "##end"))
		e->start_end = 2;
}

int			ft_parse(t_lem *e)
{
	while (get_next_line(0, &e->line) > 0)
	{
		if (e->line[0] == '#')
			ft_diese(e);
		else if (!e->stop)
		{
			e->nb_ants = ft_atoi(e->line);
			dprintf(2, "nb_ants = %d\n", e->nb_ants);
			if (!ft_str_is_num(e->line) || e->nb_ants <= 0)
				return (-1);
		}
		else if (ft_get_room(e) == -1)
				return (-1);
		e->stop++;
		ft_strdel(&e->line);
	}
	return (0);
}

int			ft_error(t_lem *e)
{
	ft_printf("Error\n");
	//FREE STRUCT
	return (-1);
}

int main(void)
{
	t_lem	*e;

	if (!(e = malloc(sizeof(t_lem))))
		return (ft_error(e));
	e->line = NULL;
	e->save = NULL;
	e->stop = 0;

	if (ft_parse(e) == -1)
		return (ft_error(e));
	//ALGO
	return (0);
}
