/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_btree_create_node.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:43 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:43 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree *tree;

	tree = malloc(sizeof(t_btree));
	if (tree)
	{
		tree->left = NULL;
		tree->right = NULL;
		tree->item = item;
	}
	return (tree);
}
