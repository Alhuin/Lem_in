/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_next.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 14:34:46 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 12:00:08 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_compare_path(int *s1, int *s2)
{
	int		i;
	int		j;
	int		err;

	printf("\nCOMPARE PATH\n--------\n");
	printf("S1 = ");
	i = -1;
	while (s1[++i] != -1)
		printf("%d ", s1[i]);
	printf("\n");
	printf("S2 = ");
	i = -1;
	while (s2[++i] != -1)
		printf("%d ", s2[i]);
	printf("\n----------\n");

 	i = 1;
	while (s1[i] != -1)
	{
		err = 0;
		j = 1;
		while (s2[j] != -1)
		{
			if (s1[i] == s2[j])
			{
				printf("nop\n\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	printf("yes\n\n");
	return (0);
}

int		ft_compare_all_path(t_lem *e, int j)
{
	int	len;
	int	k;

	len  = ft_inttablen(e->all_path[e->nb_path - 1]);
	ft_printf("len all path = %d\n", len);
//	if (ft_inttablen(e->all_path[e->nb_path - 1]) > 0)
//	ici je dois me balader sur all path
	k = 0;
	while (e->all_path[e->nb_path - 1][k] != -1)
	{
		printf("\nCOMPARE ALL PATh\n\n");
		if (ft_compare_path(e->data[e->nb_room - 1].path[e->all_path[e->nb_path - 1][k]], e->data[e->nb_room - 1].path[j]))
		{
			ft_printf("NEIN\n");
			return (1);
		}
		k++;
	}
	return (0);
}

int		ft_add_f(t_lem *e)
{
	if (e->nb_path == 0)
		e->all_path = malloc(sizeof(int*));
	else
		e->all_path = ft_realloc(e->all_path, sizeof(int*) * e->nb_path, sizeof(int*) * (e->nb_path + 1));
	e->all_path[e->nb_path] = malloc(sizeof(int) * 2);
	e->all_path[e->nb_path][1] = -1;
	e->nb_path++;
	return (0);
}

int		ft_add_s(t_lem *e, int j)
{
	int		len;

	len = ft_inttablen(e->all_path[e->nb_path - 1]);
	if (len == 1)
		e->all_path[e->nb_path - 1][0] = j;
	else
	{
		e->all_path[e->nb_path - 1] = ft_realloc(e->all_path[e->nb_path - 1], sizeof(int) * len, sizeof(int) * (len + 2));
		e->all_path[e->nb_path - 1][len + 1] = j;
		e->all_path[e->nb_path - 1][len + 2] = -1;
	}
	return (0);
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
			printf("i = %d - j = %d\n", i, j);
			if ((i == j) || !(ft_compare_path(e->data[e->nb_room - 1].path[i], e->data[e->nb_room - 1].path[j])))
			{
				if (tmp == 0)
				{
					ft_printf("new path\n");
					ft_add_f(e);
				}
				if ((i == j) || !(ft_compare_all_path(e, j)))
				{
					ft_printf("add j = %d\n", j);
					ft_add_s(e, j);
				}
			}
			tmp++;
		}
	}
	ft_printf("\n------------\n\n");
	i = -1;
	while (++i < e->nb_path - 1)
	{
		j = -1;
		ft_printf("ALL_PATH %d: ", i);
		while (e->all_path[i][++j] != -1)
			ft_printf("%d ",e->all_path[i][j]);
		ft_printf("\n");
	}

	return (0);
}
