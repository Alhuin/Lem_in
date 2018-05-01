/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:16:52 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 00:17:19 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		ft_inttablen(int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int		*ft_inttabdup(int *s1)
{
	int		*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	k = ft_inttablen(s1);
	if (!(s2 = malloc(sizeof(int) * (k + 1))))
		return (NULL);
	s2[k] = -1;
	while (s1[i] != -1)
		s2[j++] = s1[i++];
	return (s2);
}

int		*ft_inttabjoin(int *s1, int *s2)
{
	int		i;
	int		j;
	int		k;
	int		*new;

	if (s1 == NULL && s2 == NULL)
	{
		new = malloc(sizeof(int));
		new[0] = -1;
		return (new);
	}
	else if (s1 == NULL)
		return (ft_inttabdup(s2));
	else if (s2 == NULL)
		return (ft_inttabdup(s1));
	k = ft_inttablen(s1) + ft_inttablen(s2);
	new = malloc(sizeof(int) * (k + 1));
	i = -1;
	j = -1;
	while (s1[++i] != -1)
		new[++j] = s1[i];
	i = -1;
	while (s2[++i] != -1)
		new[++j] = s2[i];
	new[j] = -1;
	return (new);
}

int		*ft_inttabadd(int *s1, int k)
{
	int		*new;
	int		i;
	int		j;
	int		len;

	len = ft_inttablen(s1);
	printf("len s1 = %d\n", len);
	new = malloc(sizeof(int) * (len + 2));
	i = -1;
	j = 0;
	while (s1[++i] != -1)
		new[j++] = s1[i];
	new[j++] = k;
	new[j] = -1;
	free(s1);
	return (new);
}



int		path_manage(t_lem *e, int i, int j)
{
	if (e->data[j].path == NULL)
	{
		if (!(e->data[j].path = malloc(sizeof(int*))))
			return (-1);
		e->data[j].nb_path++;
		e->data[j].path[0] = NULL;
	}
	else
	{
		if (!(e->data[j].path = ft_realloc(e->data[j].path, sizeof(int*) * e->data[j].nb_path,
								sizeof(int*) * (e->data[j].nb_path + e->data[i].nb_path))))
				return (-1);
		e->data[j].nb_path += e->data[i].nb_path;

	}
	return (0);
}

int		path_copy(t_lem *e, int i, int j)
{
	int		k;
	int		l;

	if (e->data[i].path == NULL)
	{
		e->data[j].path[0] = malloc(sizeof(int) * 2);
		e->data[j].path[0][0] = i;
		e->data[j].path[0][1] = -1;
		return (0);
	}
	k = e->data[j].nb_path - e->data[i].nb_path;
	l = 0;
	while (k < e->data[j].nb_path)
	{
		e->data[j].path[k] = ft_inttabjoin(e->data[i].path[l], e->data[j].path[k]);
		e->data[j].path[k] = ft_inttabadd(e->data[j].path[k], i);
		k++;
		l++;
	}
	return (0);
}

void	ft_print_path(t_lem *e, int j)
{
	int l;
	int k;

	k = -1;
	dprintf(2, "\nDATA[%d]\n", j);
	while (++k < e->data[j].nb_path)
	{
		l = -1;
		dprintf(2, "PATH[%d] : ", k);
		while (e->data[j].path[k][++l] != -1)
			dprintf(2, "%d ", e->data[j].path[k][l]);
		dprintf(2, "\n");
	}

}


int		algo_main(t_lem *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->nb_room)
	{
		j = -1;
		while (++j < e->data[i].nb_links)
		{
			if (e->data[i].links[j] > i)
			{
				if (path_manage(e, i, e->data[i].links[j]))
					return (-1);
				if (path_copy(e, i, e->data[i].links[j]))
					return (-1);
				ft_print_path(e, e->data[i].links[j]);
			}
		}
	}
	ft_printf("\nNB TOTAL PATH: %d\n", e->data[i - 1].nb_path);
	return (0);
}
