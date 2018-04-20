/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_btree_apply_infix.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:42 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:42 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root)
	{
		if (root->left)
			ft_btree_apply_infix(root->left, applyf);
		applyf(root->item);
		if (root->right)
			ft_btree_apply_infix(root->right, applyf);
	}
}
