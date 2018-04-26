/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_matrice.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:17:28 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 16:18:42 by nbettach    ###    #+. /#+    ###.fr     */
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

void			data_cpy(int a, int b, t_room *tmp, t_lem *e)
{
	int i;

	i = -1;
	tmp[b].name = ft_strdup(e->data[a].name);
	tmp[b].links = malloc(sizeof(int) * e->data[a].nb_links);
	while (++i < e->data[a].nb_links)
		tmp[b].links[i] = e->data[a].links[i];
	tmp[b].room_x = e->data[a].room_x;
	tmp[b].room_y = e->data[a].room_y;
	tmp[b].nb_links = e->data[a].nb_links;
	tmp[b].dist_s = e->data[a].dist_s;
	tmp[b].dist_e = e->data[a].dist_e;
}
void			rev_data_cpy(int a, int b, t_room *tmp, t_lem *e)
{
	int i;

	i = -1;
	e->data[b].name = ft_strdup(tmp[a].name);
	e->data[b].links = malloc(sizeof(int) * tmp[a].nb_links);
	while (++i < tmp[a].nb_links)
		e->data[b].links[i] = tmp[a].links[i];
	e->data[b].room_x = tmp[a].room_x;
	e->data[b].room_y = tmp[a].room_y;
	e->data[b].nb_links = tmp[a].nb_links;
	e->data[b].dist_s = tmp[a].dist_s;
	e->data[b].dist_e = tmp[a].dist_e;
}

int			swap_data(t_lem *e, int a, int b)
{
//	int i;

//	i = -1;
	t_room		*tmp;

/*	dprintf(2, "A\ndata name =  %s\n", e->data[a].name);
	dprintf(2, "data room_x =  %d\n", e->data[a].room_x);
	dprintf(2, "data room_y =  %d\n", e->data[a].room_y);
	while (++i < e->data[a].nb_links)
		dprintf(2, "links[%d] =  %d\n", i, e->data[a].links[i]);
	i = -1;
	dprintf(2, "data nb_links =  %d\n", e->data[a].nb_links);
	dprintf(2, "data dist_s =  %d\n", e->data[a].dist_s);
	dprintf(2, "data dist_e =  %d\n", e->data[a].dist_e);
	dprintf(2, "\nB\ndata name =  %s\n", e->data[b].name);
	dprintf(2, "data room_x =  %d\n", e->data[b].room_x);
	dprintf(2, "data room_y =  %d\n", e->data[b].room_y);
	while (++i < e->data[b].nb_links)
		dprintf(2, "links[%d] =  %d\n", i, e->data[b].links[i]);
	i = -1;
	dprintf(2, "data nb_links =  %d\n", e->data[b].nb_links);
	dprintf(2, "data dist_s =  %d\n", e->data[b].dist_s);
	dprintf(2, "data dist_e =  %d\n", e->data[b].dist_e);
*/	if (!(tmp = malloc(sizeof(t_room) * e->nb_room)))
		return (-1);
	data_cpy(a, b, tmp, e); //cp data[a] dans tmp[b]
	data_cpy(b, a, tmp, e); //cp data[b] dans tmp[a]
	ft_strdel(&e->data[a].name);
	ft_intdel(&e->data[a].links);
	ft_intdel(&e->data[b].links);
	ft_strdel(&e->data[b].name);
	rev_data_cpy(a, a, tmp, e); //cp tmp[a] dans data[a]
	rev_data_cpy(b, b, tmp, e); //cp tmp[b] dans data[b]
/*	dprintf(2, "\nSWAP\nA\ndata name =  %s\n", e->data[a].name);
	dprintf(2, "data room_x =  %d\n", e->data[a].room_x);
	dprintf(2, "data room_y =  %d\n", e->data[a].room_y);
	while (++i < e->data[a].nb_links)
		dprintf(2, "links[%d] =  %d\n", i, e->data[a].links[i]);
	i = -1;
	dprintf(2, "data nb_links =  %d\n", e->data[a].nb_links);
	dprintf(2, "data dist_s =  %d\n", e->data[a].dist_s);
	dprintf(2, "data dist_e =  %d\n", e->data[a].dist_e);
	dprintf(2, "\nB\ndata name =  %s\n", e->data[b].name);
	dprintf(2, "data room_x =  %d\n", e->data[b].room_x);
	dprintf(2, "data room_y =  %d\n", e->data[b].room_y);
	while (++i < e->data[b].nb_links)
		dprintf(2, "links[%d] =  %d\n", i, e->data[b].links[i]);
	i = -1;
	dprintf(2, "data nb_links =  %d\n", e->data[b].nb_links);
	dprintf(2, "data dist_s =  %d\n", e->data[b].dist_s);
	dprintf(2, "data dist_e =  %d\n", e->data[b].dist_e);
*/
	return (0);
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
	int		tmp;
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
	{
		j = -1;
		if (i != equiv[i])
		{
			while (++j < e->nb_room)
				if (i == equiv[j])
					break;
			printf("i = %d j = %d\n", i, j);
			if (j < e->nb_room)
			{
				swap_data(e, i, j);
				tmp = i;
				equiv[i] = j;
				equiv[j] = i;
			}
			else
				printf("jump\n");
		}
		print_datalinks(e);
		print_equiv(e, equiv);
	}
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
