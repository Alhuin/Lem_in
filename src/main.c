/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:29:45 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 20:50:54 by magaspar    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"


static int			ft_check_data(t_lem *e)
{
	int i;
	int start;
	int end;

	end = 0;
	start = 0;
	i = -1;
	if (e->nb_room == 0)
		return (-1);
	while (++i < e->nb_room)
	{
		if (e->data[i].dist_s == 0)
		{
			if (e->data[i].nb_links == 0)
				return (-1);
			start++;
		}
		if (e->data[i].dist_e == 0)
			end++;
	}
	if (start != 1 || end != 1)
		return (-1);
	return (0);
}

int					check_start_end(t_lem *e)
{
	int	j;

	j = -1;
	while (++j < e->data[e->start].nb_links)
	{
		if (e->data[e->start].links[j] == e->end)
		{
			ft_printf("%s\n", e->save);
			j = 0;
			while (++j <= e->nb_ants)
				ft_printf("L%d-%s ", j, e->data[e->end].name);
			ft_printf("\n");
			return (1);
		}
	}
	return (0);
}

void				ft_free_play(int **to_free)
{
	int i;

	i = -1;
	if (to_free == NULL)
		return ;
	while (to_free[++i] != NULL)
		ft_intdel(&to_free[i]);
	free(to_free);
	to_free = NULL;
}

int					**save_play(int **tmp)
{
	int i;
	int len;
	int **play;

	len = 0;
	i = -1;
	while (tmp[len])
		len++;
	if (!(play = malloc(sizeof(int *) * (len + 1))))
		return (NULL);
	play[len] = NULL;
	while (++i < len)
	{
		if (!(play[i] = malloc(sizeof(int) * 2)))
			return (NULL);
		play[i][0] = tmp[i][0];
		play[i][1] = tmp[i][1];
	}
	return (play);
}

int					make_play(t_lem *e)
{
	int i;
	int **tmp;
	int plays;

	plays = -1;
	tmp = NULL;
	i = -1;
	while (++i < e->nb_path)
	{
		tmp = count_plays(e->data[e->nb_room - 1].path, e->all_path, e, i);
		if (plays == -1 || plays > tmp[0][0])
		{
			ft_free_play(e->play);
			if (!(e->play = save_play(tmp)))
				return (-1);
			plays = e->play[0][0];
			e->poss_to_play = i;
		}
		ft_free_play(tmp);
	}
	return (0);
}

int					main(void)
{
	t_lem	*e;

	if (init_env(&e) == -1)
		return (ft_error(e));
	if (ft_parse(e, NULL) == -1 || ft_check_data(e) == -1)
		return (ft_error(e));
	if (!check_start_end(e))
	{
		if (ft_sorting(e) == -1)
			return (ft_error(e));
		if (algo_main(e) == -1)
			return (ft_error(e));
		if (algo_next(e))
			return (ft_error(e));
		sort_all_path(e, e->data[e->nb_room - 1].path);
		make_play(e);
		ft_printf("%s\n", e->save);
		move_ants(e, e->poss_to_play);
	}
	free_env(&e);
	return (0);
}
