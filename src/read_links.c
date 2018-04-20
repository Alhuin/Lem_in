#include "../includes/lemin.h"

int			ft_init_links(t_lem *e, int i, int j)
{
	e->data[i].nb_links++;
	if (!e->data[i].links)
	{
		if (!(e->data[i].links = malloc(sizeof(int))))
			return (-1);
	}
	else
	{
		if (!(e->data[i].links = ft_realloc(e->data[i].links, sizeof(int) * (e->data[i].nb_links -1),
						sizeof(t_room) * e->data[i].nb_links)))
			return (-1);
	}
	e->data[i].links[e->data[i].nb_links - 1] = j;
	e->data[j].nb_links++;
	if (!e->data[j].links)
	{
		if (!(e->data[j].links = malloc(sizeof(int))))
			return (-1);
	}
	else
	{
		if (!(e->data[j].links = ft_realloc(e->data[j].links, sizeof(int) * (e->data[j].nb_links -1),
						sizeof(t_room) * e->data[j].nb_links)))
			return (-1);
	}
	e->data[j].links[e->data[j].nb_links - 1] = i;
	return (0);
}

char		**ft_get_links(t_lem *e)
{
	char	**t;

	if (!(t = ft_strsplit(e->line, '-')))
		return (NULL);
	return (t);
}
