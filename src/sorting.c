/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   nassim_tools.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/26 17:34:13 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 14:28:27 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int					data_sort(t_lem *e, int *equiv)
{
	t_room	*tmp;
	int		i;
	int		k;

	k = -1;
	if (!(tmp = malloc(sizeof(t_room) * e->nb_room)))
		return (-1);
	while (++k < e->nb_room)
	{
		i = 0;
		while (i < e->nb_room && equiv[i] != k)
			i++;
		if (i == e->nb_room)
			continue ;
		data_to_tmp(i, k, tmp, e);
		ft_strdel(&e->data[i].name);
		ft_intdel(&e->data[i].links);
	}
	k = -1;
	while (++k < e->nb_room)
	{
		if (equiv[k] == -1)
			continue ;
		tmp_to_data(k, k, tmp, e);
		ft_strdel(&tmp[k].name);
		ft_intdel(&tmp[k].links);
	}
	free(tmp);
	return (0);
}

void				data_scan(t_lem *e, int *equiv)
{
	int i;
	int k;
	int j;
	int tour;

	k = 0;
	tour = -1;
	while (++tour < e->nb_room)
	{
		i = -1;
		while (++i < e->nb_room)
		{
			if (equiv[i] == tour)
			{
				j = -1;
				while (++j < e->data[i].nb_links)
					if (equiv[e->data[i].links[j]] == -1)
						equiv[e->data[i].links[j]] = ++k;
			}
		}
	}
	i = -1;
	while (++i < e->nb_room)
	{
		if (equiv[i] == - 1)
			equiv[i] = ++k;
	}
	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
			e->data[i].links[j] = equiv[e->data[i].links[j]];
	}
}

int					ft_sorting(t_lem *e)
{
	int i;
	int equiv[e->nb_room];

	//DEBUT TABLEAU EQUIV*/
	i = -1;
	while (++i < e->nb_room)
	{
		if (i == e->end)
			equiv[i] = 0;
		else if (i == e->start)
			equiv[i] = e->nb_room - 1;
		else
			equiv[i] = -1;
	}
	//SCAN data POUR AVOIR L'ORDRE && METTRE EQUIVALENCE DATA[i].LINKS
	data_scan(e, equiv);
	data_sort(e, equiv);
//	dprintf(1, "print all path, %d \n\n\n\n", e->nb_path);
//	ft_print_allpath(e);
	return (0);
}

void	ft_print_allpath(t_lem *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < e->nb_path)
	{
		j = -1;
		ft_printf("ALL_PATH %d: ", i);
		while (e->all_path[i][++j] != -1)
			ft_printf("%d ",e->all_path[i][j]);
		ft_printf("\n");
	}
}

void	ft_print_last(t_lem *e)
{
	int	i;
	int	j;

	i = -1;
	while (++i < e->data[e->nb_room -1].nb_path)
	{
		j = 0;
		printf("Path[%d] : ",i);
		while (e->data[e->nb_room - 1].path[i][j] != -1)
		{
			printf("%d ", e->data[e->nb_room - 1].path[i][j]);
			j++;
		}
		printf("\n");
	}
}

/*
void	ft_print_path(t_lem *e, int j, int i)
{
	int l;
	int k;

	k = -1;
	dprintf(2, "\ni = %d\nDATA[%d] name = %s\n", i, j, e->data[j].name);
	while (++k < e->data[j].nb_path)
	{
		l = -1;
		dprintf(2, "PATH[%d] : ", k);
		while (e->data[j].path[k][++l] != -1)
			dprintf(2, "%d ", e->data[j].path[k][l]);
		dprintf(2, "\n");
	}
}

void	ft_print_dataname(t_lem *e)
{
	int i;

	i = -1;
	while (++i < e->nb_room)
		printf("DATA[%d].name = %s\n", i, e->data[i].name);
}*/
