#include "../includes/lemin.h"

void	print_matrix(t_lem *e);

int		make_matrice(t_lem *e)
{
	int		i;
	int		j;
	int		f;
	int		k;

	i = -1;
	if (!(e->matrix = malloc(sizeof(t_mat*) * e->nb_room)))
		return (-1);
	while (++i < e->nb_room)
	{
		j = -1;
		if (!(e->matrix[i] = malloc(sizeof(t_mat) * e->nb_room)))
			return (-1);
		while (++j < e->nb_room)
		{
			f = 0;
			k = -1;
			while (++k < e->data[j].nb_links)
				if (e->data[j].links[k] == i)
					f = 1;
				e->matrix[i][j].l = (f == 1 ? 1 : 0);
		}
	}
	print_matrix(e);
	return (0);
}

void	print_matrix(t_lem *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->nb_room)
	{
		j = 0;
		while(j < e->nb_room)
		{
			ft_printf("%d ", e->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
