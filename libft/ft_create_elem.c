/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_elem.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:43 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:43 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list2	*ft_create_elem(void *data)
{
	t_list2 *list;

	list = (t_list2*)malloc(sizeof(t_list2));
	if (list)
	{
		list->data = data;
		list->next = NULL;
	}
	return (list);
}
