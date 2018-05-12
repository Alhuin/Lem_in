/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dguelpa <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/07 16:00:01 by dguelpa      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 17:10:15 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	move_forward(t_lem *e, int i, int *path)
{
	if (i == 1)
	{
		ft_printf("L%d-%s ", e->data[path[i]].ant, e->data[0].name);
		e->ants_arrived++;
	}
	else
	{
		ft_printf("L%d-%s ", e->data[path[i]].ant, e->data[path[i - 1]].name);
		e->data[path[i - 1]].ant = e->data[path[i]].ant;
	}
	e->data[path[i]].ant = 0;
}

void	send_ant(t_lem *e, int j, int a, int room)
{
	if (e->play[j][1] > 0)
	{
		ft_printf("L%d-%s ", a, e->data[room].name);
		e->data[room].ant = a++;
		e->play[j][1]--;
		if (e->nb_room == 2)
			e->ants_arrived++;
	}
}

int		move_ants(t_lem *e, int play, int nb_paths, int a)
{
	int	i;
	int	j;
	int	path_len;
	int	*path;

	while (e->ants_arrived < e->nb_ants)
	{
		j = -1;
		while (++j < nb_paths)
		{
			path = e->data[e->nb_room - 1].path[e->all_path[play][j]];
			path_len = ft_inttablen(path);
			i = -1;
			while (++i <= path_len)
			{
				if (i == path_len)
					send_ant(e, j, a, path[i - 1]);
				else if (e->data[path[i]].ant != 0 && i)
					move_forward(e, i, path);
			}
		}
		ft_printf("\n");
	}
	return (0);
}
