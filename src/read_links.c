/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_links.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:20:38 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 15:51:35 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			malloc_links(t_lem *e, int j)
{
	if (!e->data[j].links)
	{
		if (!(e->data[j].links = malloc(sizeof(int))))
			return (-1);
	}
	else
	{
		if (!(e->data[j].links = ft_realloc(e->data[j].links, sizeof(int) *
			(e->data[j].nb_links - 1), sizeof(t_room) * e->data[j].nb_links)))
			return (-1);
	}
	return (0);
}

int			ft_init_links(t_lem *e, int i, int j)
{
	e->data[i].nb_links++;
	if (!e->data[i].links)
	{
		if (!(e->data[i].links = malloc(sizeof(int))))
			return (-1);
	}
	else
	{
		if (!(e->data[i].links = ft_realloc(e->data[i].links, sizeof(int) *
			(e->data[i].nb_links - 1), sizeof(t_room) * e->data[i].nb_links)))
			return (-1);
	}
	e->data[i].links[e->data[i].nb_links - 1] = j;
	e->data[j].nb_links++;
	if (malloc_links(e, j) == -1)
		return (-1);
	e->data[j].links[e->data[j].nb_links - 1] = i;
	return (0);
}

char		**ft_get_links(t_lem *e)
{
	char	**t;

	if (!(t = ft_strsplit(e->line, '-')))
		return (NULL);
	return (t);
}
