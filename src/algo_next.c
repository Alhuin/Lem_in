/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_next.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 14:34:46 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 15:25:18 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_compare_path(int *s1, int *s2)
{
	int		i;
	int		j;
	int		err;

	i = 1;
	while (s1[i] != -1)
	{
		err = 0;
		j = 1;
		while (s2[j] != -1)
		{
			if (s1[i] == s2[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_compare_all_path(t_lem *e, int j)
{
	int	len;
	int	k;

	len = ft_inttablen(e->all_path[e->nb_path - 1]);
	k = 0;
	if (e->all_path[e->nb_path - 1][0] == -2)
		return (0);
	while (e->all_path[e->nb_path - 1][k] != -1)
	{
		if (ft_compare_path(e->data[e->nb_room - 1].path[
					e->all_path[e->nb_path - 1][k]],
					e->data[e->nb_room - 1].path[j]))
			return (1);
		k++;
	}
	return (0);
}

int		ft_add_f(t_lem *e)
{
	if (e->nb_path == 0)
	{
		if (!(e->all_path = malloc(sizeof(int*))))
			return (-1);
	}
	else
	{
		if (!(e->all_path = ft_realloc(e->all_path, sizeof(int*) * e->nb_path,
						sizeof(int*) * (e->nb_path + 1))))
			return (-1);
	}
	if (!(e->all_path[e->nb_path] = malloc(sizeof(int) * 2)))
		return (-1);
	e->all_path[e->nb_path][0] = -2;
	e->all_path[e->nb_path][1] = -1;
	e->nb_path++;
	return (0);
}

int		ft_add_s(t_lem *e, int j)
{
	int		len;

	len = ft_inttablen(e->all_path[e->nb_path - 1]);
	if (len == 1 && e->all_path[e->nb_path - 1][0] == -2)
		e->all_path[e->nb_path - 1][0] = j;
	else
	{
		if (!(e->all_path[e->nb_path - 1] = ft_realloc(
				e->all_path[e->nb_path - 1],
				sizeof(int) * (len + 1), sizeof(int) * (len + 2))))
			return (-1);
		e->all_path[e->nb_path - 1][len] = j;
		e->all_path[e->nb_path - 1][len + 1] = -1;
	}
	return (0);
}

int		final_path_poss(t_lem *e)
{
	int i;
	int len;
	int j;
	int k;
	int **tmp;

	i = -1;
	len = 0;
	while (++i < e->nb_path)
	{
		if (e->all_path[i][0] != -1)
			len++;
	}
	if (!(tmp = malloc(sizeof(int *) * len)))
		return (-1);
	i = 0;
	j = -1;
	while (++j < len)
	{
		k = 0;
		while (i < e->nb_path && e->all_path[i][0] == -1)
			i++;
		if (!(tmp[j] = malloc(sizeof(int) * (ft_inttablen(e->all_path[i])
							+ 1))))
			return (-1);
		while (e->all_path[i][k] != -1)
		{
			tmp[j][k] = e->all_path[i][k];
			k++;
		}
		tmp[j][k] = -1;
		i++;
	}
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

int		algo_next(t_lem *e)
{
	int		i;
	int		j;
	int		tmp;

	e->nb_path = 0;
	i = -1;
	while (++i < e->data[e->nb_room - 1].nb_path)
	{
		j = -1;
		tmp = 0;
		while (++j < e->data[e->nb_room - 1].nb_path)
		{
			if ((i == j) || !(ft_compare_path(e->data[e->nb_room - 1].path[i],
							e->data[e->nb_room - 1].path[j])))
			{
				if (tmp == 0)
					if (ft_add_f(e))
						return (-1);
				if ((i == j) || !(ft_compare_all_path(e, j)))
					if (ft_add_s(e, j))
						return (-1);
				tmp++;
			}
		}
	}
	if (check_double(e))
		return (-1);
//	dprintf(1, "printing new all_path\n");
//	ft_print_allpath(e);

	return (0);
}
