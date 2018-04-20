/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:45 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 16:57:22 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstdelone(t_ptf **s)
{
	if (s && *s)
	{
		if ((*s)->arg)
			ft_strdel(&(*s)->arg);
		if ((*s)->warg)
			free((*s)->warg);
		if ((*s)->option)
			ft_strdel(&(*s)->option);
	}
}
