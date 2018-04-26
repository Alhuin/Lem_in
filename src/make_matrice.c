/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:17:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 13:27:07 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"



void		swap_matrix(t_lem *e, int a, int b)
{
	int		*tmp;
	
	tmp = e->matrix[a];
	e->matrix[a] = e->matrix[b];
	e->matrix[b] = tmp;
}

void		swap_data(t_lem *e, int a, int b)
{
	t_room		*tmp;

	tmp = &(e->data[a]);
	e->data[a] = e->data[b];
	e->data[b] = *tmp;
}

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


static void		print_equiv(t_lem *e, int *equiv)
{
	int		i;

	i = 0;
	while (i < e->nb_room)
	{
		ft_printf("%d - ", equiv[i]);
		i++;
	}
	ft_printf("\n");
}

static void		print_datalinks(t_lem *e)
{
	int i;
	int j;

	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		printf("data[%d] = ",i);
		while(++j < e->data[i].nb_links)
			printf(" %d ",e->data[i].links[j]);
		printf(" - %s\n", e->data[i].name);
	}
}

int		sort_matrix(t_lem *e)
{
	int		i;
	int		j;
	int		k;
	int		tour;
	int		equiv[e->nb_room];

	//MALLOC NOUVELLE MATRIX
	i = -1;
	if (!(e->sorted = malloc(sizeof(int*) * e->nb_room)))
		return (-1);
	while (++i < e->nb_room)
		if (!(e->sorted[i] = malloc(sizeof(int) * e->nb_room)))
			return (-1);

	//DEBUT TABLEAU EQUIV
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
	print_equiv(e, equiv);

	printf("\n nb_room = %d\n", e->nb_room);
	//SCAN data POUR AVOIR L'ORDRE
	k = 0;
	tour = 0;
	while (tour < e->nb_room)
	{
		i = -1;
		while (++i < e->nb_room)
			if (equiv[i] == tour)
				break;
		/*j = -1;
		while (++j < e->nb_room)
			if (e->matrix[i][j] == 1  && equiv[j] == -1)
			{
				equiv[j] = ++k;
				printf("j = %d k = %d\n", j, k);
			}*/
		j = -1;
		while (++j < e->data[i].nb_links)
			if (equiv[e->data[i].links[j]] == -1)
				equiv[e->data[i].links[j]] = ++k;
		tour++;
	}
	print_equiv(e, equiv);

	//METTRE EQUIVALENCE DATA[i].LINKS
	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
			e->data[i].links[j] = equiv[e->data[i].links[j]];
	}

	//TRIER DATA[i]
	i = -1;
	while (++i < e->nb_room)
		if (i == equiv[i])
			swap_data(e, i, equiv[i]);
	return (0);
}


int				make_matricei_suit(t_lem *e)
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
	return (0);
}

int		make_matrice(t_lem *e)
{
	make_matricei_suit(e);
	print_matrix(e);
	printf("DATA NON SORTED\n");
	print_datalinks(e);
	//swap_matrix(e, 0, 2);
	ft_printf("\n");
	//print_matrix(e);
	sort_matrix(e);
	printf("DATA SORTED\n");
	print_datalinks(e);
	printf("\nDATA SORTED\n");
	make_matricei_suit(e);
	print_matrix(e);
	ft_printf("\n");


	return (0);
}
