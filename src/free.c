/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 20:29:21 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 20:44:14 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		free_node(t_forest **node)
{
	int	i;
	int links;

	links = (*node)->room->nb_links;
	i = -1;
	ft_strdel(&(*node)->room->name);
	free((*node)->room);
	while (++i < links)
		free((*node)->subtree[i]);
	free((*node)->parent);
	free((*node)->subtree);
	free(*node);
}

void		free_tree(t_forest **tree)
{
	int i;

	i = -1;
	if ((*tree)->subtree)
	{
		while (++i < (*tree)->room->nb_links)
			free_tree(&(*tree)->subtree[i]);
	}
	if (*tree)
		free_node(tree);
}
