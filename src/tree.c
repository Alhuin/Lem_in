/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tree.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 15:33:34 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 21:45:16 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

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


void		ft_addfloor(t_lem *e)
{
	int		i;
	int		j;
	int		k;
	int		pass;
	int		size_mlc;
	int		tmp;

	i = 0;
	pass = 2;
	e->sorted = malloc(sizeof(int) * 1);
	while (pass < e->nb_room)
	{
		if (e->sorted == NULL)
		{
			e->sorted = malloc(sizeof(int*));
			e->sorted[0] = ft_strdup(e->data[e->end].links); // STRDUP INT
			pass += e->data[e->end].nb_links;
		}
		else
		{
			e->sorted = ft_realloc(e->sorted, sizeof(int*) * i, sizeof(int*) * (i + 1));
			size_mlc = 0;
			j = 0;
			while (j < ft_strlen(e->saved[i - 1])) //STRLEN INT
			{
				tmp = e->saved[i - 1][j];
				k = 0;
				while (k < ft_strlen(e->data[tmp].links))
				{

					k++;
				}
				j++;
			}
			e->sorted[i] = malloc(sizeof(int) * size_mlc);
			j = 0;
			while (j < size_mlc)
			{
				s->sorted[i][j] = ;
				j++;
			}
			pass += ft_strlen(e->sorted[i]); // STRLEN INT
		}
		i++;
	}

}
