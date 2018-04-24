/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tree.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 15:33:34 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 18:54:20 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		g_pass = 0;

int		ft_createnode(t_lem *e, t_room **room, t_forest **tocreate)
{
	t_forest	*node;

	if (!(node = malloc(sizeof(t_forest))))
		return (-1);
	if (!(node->subtree = malloc(sizeof(t_forest) * ((*room)->nb_links - 1))))
		return (-1);
	(*node).room = *room;
	node->parent = NULL;
	node->subtree = NULL;
	*tocreate = node;
	return (0);
}

int			ft_addnode(t_lem *e, t_room **room, t_forest **tree)
{
	int		i;

	i = 0;
	if (*tree == NULL)
		return (ft_createnode(e, room, tree));
	else
	{
		if ((*tree)->subtree == NULL)
			ft_addnode(e, room, &(*tree)->subtree[0]);
		else
		{
			while ((*tree)->subtree[i] && i < (*room)->nb_links)
				i++;
			if (i != (*room)->nb_links)
				ft_addnode(e, room, &(*tree)->subtree[i]);
			else
				return (-1);
		}
	}
	return (0);
}

void		ft_exfloor(int k, t_lem *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (e->matrix[k][i])
		i++;
	if (!k || k == e->nb_room - 1)
		e->sorted[k] = malloc(sizeof(int) * j);
	else
		e->sorted[k] = malloc(sizeof(int) * (j - 1));

	while ()
	{
	
	}

}


void		ft_addfloor(t_lem *e)
{
	int		i;

	e->sorted = malloc(sizeof(int) * (e->nb_room - 1));
	i = 0;
	while (g_pass < e->nb_room)
	{
		ft_exfloor(i, e);
		i++;
	}

}
