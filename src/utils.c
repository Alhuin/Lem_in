/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:34:01 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 13:15:23 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int				ft_inttablen(int *tab)
{
	int		i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int				*ft_inttabdup(int *s1)
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

int				*ft_inttabjoin(int *s1, int *s2)
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
	if (!(new = malloc(sizeof(int) * (k + 1))))
		return (NULL);
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

int				ft_diese(t_lem *e)
{
	if (!ft_strncmp(e->line, "##", 2))
	{
		if (!ft_strcmp(e->line, "##start"))
			e->start_end = 1;
		else if (!ft_strcmp(e->line, "##end"))
			e->start_end = 2;
		else
			return (-2);
		if (e->start_end == 1 && e->start != -1)
			return (-1);
		else if (e->start_end == 2 && e->end != -1)
			return (-1);
	}
	return (0);
}

int				ft_error(t_lem *e)
{
	free_env(&e);
	ft_printf("ERROR\n");
	return (-1);
}

int				init_env(t_lem **e)
{
	if (!(*e = malloc(sizeof(t_lem))))
		return (-1);
	(*e)->line = NULL;
	(*e)->save = NULL;
	(*e)->stop = 0;
	(*e)->data = NULL;
	(*e)->nb_room = 0;
	(*e)->start_end = 0;
	(*e)->total_nb_links = 0;
	(*e)->error = 0;
	(*e)->room = 0;
	(*e)->start = -1;
	(*e)->end = -1;
	(*e)->poss_to_play = 0;
	(*e)->nb_path = 0;
	(*e)->all_path = NULL;
	(*e)->play = NULL;
	return (0);
}
