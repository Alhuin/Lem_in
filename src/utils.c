/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:34:01 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 13:10:57 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int					ft_diese(t_lem *e)
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

int					ft_error(t_lem *e)
{
	free_env(&e);
	ft_printf("ERROR\n");
	return (-1);
}

int					init_env(t_lem **e)
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
	(*e)->matrix = NULL;
	(*e)->sorted = NULL;
	(*e)->error = 0;
	(*e)->room = 0;
	(*e)->start = -1;
	(*e)->end = -1;
	(*e)->poss_to_play = 0;
	return (0);
}
