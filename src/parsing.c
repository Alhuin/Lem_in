/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/11 10:28:43 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 10:56:38 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			deal_links(char **t, t_lem *e)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (t[++i])
		if (ft_check_room_name(e, t[i], 2) == -1)
			return (-1);
	if (i != 2)
		e->error = 1;
	i = 0;
	while (i < e->nb_room && ft_strcmp(e->data[i].name, t[0]))
		i++;
	while (j < e->nb_room && ft_strcmp(e->data[j].name, t[1]))
		j++;
	if (ft_init_links(e, i, j) == -1)
		return (-1);
	ft_free_tmp(t);
	return (0);
}

static int			deal_room(char **t, t_lem *e)
{
	if (ft_check_room_name(e, t[0], 1) == -1)
		return (-1);
	if (ft_check_room_coord(e, ft_atoi(t[1]), ft_atoi(t[2])) == -1)
		return (-1);
	if (ft_init_room(t[0], e, ft_atoi(t[1]), ft_atoi(t[2])) == -1)
		return (-1);
	ft_free_tmp(t);
	return (0);
}

int					ft_parse(t_lem *e, char **t)
{
	int		links;
	int		ret;

	ret = 0;
	links = 0;
	while ((ret = get_next_line(0, &e->line)))
	{
		if (ret == -2)
			return (-1);
		if (e->line[0] == '#')
		{
			if ((ret = ft_diese(e)) == -1)
				return (-1);
			else if (ret == -2)
				return (-2);
		}
		else if (!e->stop++)
		{
			e->nb_ants = ft_atoi(e->line);
			if (!ft_str_is_num(e->line) || e->nb_ants <= 0)
				return (-1);
		}
		else if (links == 0 && (t = ft_get_room(e)))
		{
			if (deal_room(t, e) == -1)
				return (-1);
		}
		else if (e->nb_room > 0 && (t = ft_get_links(e)))
		{
			if (deal_links(t, e) == -1)
				return (-2);
			links++;
		}
		else
		{
			if (links > 0)
				return (-2);
			else
				return (-1);
		}
		e->save = ft_strjoin(ft_strjoin(e->save, e->line, 2), "\n", 1);
	}
	if (links == 0 || e->error != 0)
		return (-1);
	return (0);
}
