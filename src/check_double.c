/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_double.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/12 11:02:06 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 11:19:38 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		**final_path_poss_next(t_lem *e, int **tmp, int len, int i)
{
	int		j;
	int		k;

	j = -1;
	while (++j < len)
	{
		k = 0;
		while (i < e->nb_path && e->all_path[i][0] == -1)
			i++;
		if (!(tmp[j] = malloc(sizeof(int) * (ft_inttablen(e->all_path[i])
							+ 1))))
			return (NULL);
		while (e->all_path[i][k] != -1)
		{
			tmp[j][k] = e->all_path[i][k];
			k++;
		}
		tmp[j][k] = -1;
		i++;
	}
	return (tmp);
}

int		final_path_poss(t_lem *e)
{
	int		i;
	int		len;
	int		tmp_nbpath;
	int		**tmp;

	i = -1;
	len = 0;
	while (++i < e->nb_path)
	{
		if (e->all_path[i][0] != -1)
			len++;
	}
	if (!(tmp = malloc(sizeof(int *) * len)))
		return (-1);
	tmp_nbpath = e->nb_path;
	if ((tmp = final_path_poss_next(e, tmp, len, 0)) == NULL)
		return (-1);
	i = -1;
	while (++i < e->nb_path)
		ft_intdel(&e->all_path[i]);
	free(e->all_path);
	e->all_path = tmp;
	e->nb_path = len;
	return (0);
}

int		check_double(t_lem *e)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < e->nb_path - 1)
	{
		j = i;
		while (++j < e->nb_path)
		{
			k = 0;
			if (ft_inttablen(e->all_path[i]) != ft_inttablen(e->all_path[j]))
				continue ;
			else
			{
				while (e->all_path[i][k] == e->all_path[j][k]
						&& e->all_path[i][k] != -1 && e->all_path[j][k] != -1)
					k++;
				if (e->all_path[i][k] == -1 && e->all_path[j][k] == -1)
					e->all_path[i][0] = -1;
			}
		}
	}
	return (final_path_poss(e));
}
