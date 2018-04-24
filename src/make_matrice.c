/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:17:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 00:43:38 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void		print_matrix(t_lem *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->nb_room)
	{
		j = 0;
		while (j < e->nb_room)
		{
			ft_printf("%d ", e->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int				make_matrice(t_lem *e)
{
	int		i;
	int		j;
	int		f;
	int		k;

	i = -1;
	if (!(e->matrix = malloc(sizeof(int *) * e->nb_room)))
		return (-1);
	while (++i < e->nb_room)
	{
		j = -1;
		if (!(e->matrix[i] = malloc(sizeof(int) * e->nb_room)))
			return (-1);
		while (++j < e->nb_room)
		{
			f = 0;
			k = -1;
			while (++k < e->data[j].nb_links)
				if (e->data[j].links[k] == i)
					f = 1;
			e->matrix[i][j] = (f == 1 ? 1 : 0);
		}
	}
	print_matrix(e);
	return (0);
}
