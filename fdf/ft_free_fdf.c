/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_fdf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 17:11:41 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:00:06 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_fdf(t_fdf *s)
{
	int j;
	int y;

	j = 0;
	y = s->y_max;
	while (y > 0)
	{
		free(s->map[j]);
		j++;
		y--;
	}
	free(s->map);
}
