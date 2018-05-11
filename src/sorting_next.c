/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <jjanin-r@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:17:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 10:50:29 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			data_to_tmp(int a, int b, t_room *tmp, t_lem *e)
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

void			tmp_to_data(int a, int b, t_room *tmp, t_lem *e)
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
