/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_ants.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dguelpa <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/07 16:00:01 by dguelpa      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 19:36:10 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*int	do_it(t_lem *e, int play)
{
	int	ants_added;

	ants_added = 0;

	return (ants_added);
}
*/
int	move_ants(t_lem *e, int play)
{
	int	i;
	int	j;
	int	a;
	int	ants_arrived;
	int	nb_paths;
	int	path_len;
	int	*path;

	nb_paths = ft_inttablen(e->all_path[play]);
	dprintf(1, "nb_paths = %d\n", nb_paths);
	ants_arrived = 0;
	a = 1;
	while (ants_arrived < e->nb_ants)
	{
		j = -1;
		while (++j < nb_paths)
		{
			path = e->data[e->nb_room - 1].path[e->all_path[play][j]];
			path_len = ft_inttablen(path);
			i = -1;
//			dprintf(1, "path_len = %d\n", path_len);
//			print_inttab(path);
//			dprintf(1, "e->data bite = %s | %s\n", e->data[0].name, e->data[1].name);
			while (++i <= path_len)
			{
//				dprintf(1, "ZOB1 i = %d\n", i);
				if (i == path_len)
				{
//					dprintf(1, "START\n");
					if (e->play[j][1] > 0)
					{
						ft_printf("L%d-%s ", a, e->data[path[i - 1]].name);
						e->data[path[i - 1]].ant = a++;
						e->play[j][1]--;
					}
				}
				else if (e->data[path[i]].ant != 0)
				{
					if (i == 1)
					{
//						dprintf(1, "FIN\n");
						ft_printf("L%d-%s ", e->data[path[i]].ant, e->data[0].name);
						ants_arrived++;
					}
					else
					{
//						dprintf(1, "ZOB2\n");
						ft_printf("L%d-%s ", e->data[path[i]].ant, e->data[path[i - 1]].name);
						e->data[path[i - 1]].ant = e->data[path[i]].ant;
					}
					e->data[path[i]].ant = 0;
				}
			}
		}
		ft_printf("\n");
		dprintf(1, "--- END OF TURN ---\n");
	}
	dprintf(2, "PUTAIN ANTS ARRIVED = %d\n", ants_arrived);
	return (0);
}
