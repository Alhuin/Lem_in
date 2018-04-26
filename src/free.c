/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 20:29:21 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 17:22:49 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_intdel(int **as)
{
	if (as && *as)
	{
		free(*as);
		(*as) = NULL;
	}
}

static void		free_node(t_forest **node)
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

void			free_tree(t_forest **tree)
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

void			free_env(t_lem **e)
{
	int i;

	i = -1;
	free((*e)->data);
	ft_strdel(&(*e)->line);
	ft_strdel(&(*e)->save);
	if ((*e)->sorted)
		while (++i < (*e)->nb_room)
			ft_intdel(&(*e)->sorted[i]);
	i = -1;
	if ((*e)->matrix)
		while (++i < (*e)->nb_room)
			ft_intdel(&(*e)->matrix[i]);
	free(*e);
}
