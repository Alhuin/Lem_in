/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 20:29:21 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 20:34:50 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		free_node(t_forest **node)
{
	ft_strdel(&(*node)->room->name);

}

void		free_tree(t_forest **tree)
{
	if ((*tree)->subtree)
	{
		free_tree((*tree)->subtree);
	if (*tree)
		free_node(tree);
}
