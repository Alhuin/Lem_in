/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 20:29:21 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 18:28:29 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

void			ft_intdel(int **as)
{
	if (as && *as)
	{
		free(*as);
		(*as) = NULL;
	}
}

void			free_env(t_lem **e)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (++i < (*e)->nb_room)
	{
		ft_strdel(&(*e)->data[i].name);
		ft_intdel(&(*e)->data[i].links);
		while (++j < (*e)->data[i].nb_path)
			ft_intdel(&(*e)->data[i].path[j]);
		free((*e)->data[i].path);
	}
	free((*e)->data);
	j = -1;
	while ((*e)->play && ++j < ft_inttablen((*e)->all_path[(*e)->poss_to_play]))
		ft_intdel(&(*e)->play[j]);
	free((*e)->play);
	j = -1;
	while ((*e)->all_path && ++j < (*e)->nb_path)
		ft_intdel(&(*e)->all_path[j]);
	free((*e)->all_path);
	ft_strdel(&(*e)->line);
	ft_strdel(&(*e)->save);
	free(*e);
}
