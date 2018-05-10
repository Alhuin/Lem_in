/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:29:45 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 13:29:35 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int			deal_links(char **t, t_lem *e)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (t[++i])
		if (ft_check_room_name(e, t[i], 2) == -1)
			return (-1);
	if (i != 2)
		e->error = 1;
	i = 0;
	while (i < e->nb_room && ft_strcmp(e->data[i].name, t[0]))
		i++;
	while (j < e->nb_room && ft_strcmp(e->data[j].name, t[1]))
		j++;
	if (ft_init_links(e, i, j) == -1)
		return (-1);
	ft_free_tmp(t);
	return (0);
}

static int			deal_room(char **t, t_lem *e)
{
	if (ft_check_room_name(e, t[0], 1) == -1)
		return (-1);
	if (ft_check_room_coord(e, ft_atoi(t[1]), ft_atoi(t[2])) == -1)
		return (-1);
	if (ft_init_room(t[0], e, ft_atoi(t[1]), ft_atoi(t[2])) == -1)
		return (-1);
	ft_free_tmp(t);
	return (0);
}

int					ft_parse(t_lem *e, char **t)
{
	int links;
	int	ret;

	ret = 0;
	links = 0;
	while ((ret = get_next_line(0, &e->line)))
	{
		if (ret == -2)
			return (-1);
		if (e->line[0] == '#')
		{
			if ((ret =ft_diese(e)) == -1)
				return (-1);
			else if (ret == -2)
				return (-2);
		}
		else if (!e->stop++)
		{
			e->nb_ants = ft_atoi(e->line);
			if (!ft_str_is_num(e->line) || e->nb_ants <= 0)
				return (-1);
		}
		else if (links == 0 && (t = ft_get_room(e)))
		{
			if (deal_room(t, e) == -1)
				return (-1);
		}
		else if (e->nb_room > 0 && (t = ft_get_links(e)))
		{
			if (deal_links(t, e) == -1)
				return (-2);
			links++;
		}
		else
		{
			if (links > 0)
				return (-2);
			else
				return (-1);
		}
		e->save = ft_strjoin(ft_strjoin(e->save, e->line, 2), "\n", 1);
	}
	if (links == 0 || e->error != 0)
		return (-1);
	return (0);
}

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

void				make_play(t_lem *e)
{
	int i;
	int j;
	int **tmp;
	int play;
	
	play = -1;
	tmp = NULL;
	i = -1;
	//	dprintf(1, "\nnb_ants = %d\nnb_poss = %d\n", e->nb_ants, e->nb_path);
	// CHECK DE LA MEILLEURE POSSIBILITE
	while (++i < e->nb_path)
	{
		tmp = count_plays(e->data[e->nb_room - 1].path, e->all_path, e, i);
//		dprintf(1, "poss %d would take %d plays\n", i, tmp[0][0]);
		if (play == -1 || play > tmp[0][0])
		{
			e->play = tmp;
			play = e->play[0][0];
			e->poss_to_play = i;
		}
		else if (tmp)
		{
			j = -1;
			while (tmp[++j])
				ft_intdel(&tmp[j]);
			free(tmp);
		}
	}
}

int					main(void)
{
	t_lem	*e;
//	int		i;
//	int		j;
//	int play;
//	int poss_to_play;
//	int **tmp;

//	tmp = NULL;
//	play = -1;
//	poss_to_play = 0;
	if (init_env(&e) == -1)
		return (ft_error(e));
	if (ft_parse(e, NULL) == -1 || ft_check_data(e) == -1)
		return (ft_error(e));
	e->all_path = NULL;
	e->play = NULL;
	make_matrice(e);
	if (algo_main(e) == -1)
		return (ft_error(e));
	//	ft_printf("\n PATH MADE \n");
//	i = -1;
//	while (++i < e->data[e->nb_room - 1].nb_path)
//	{
//		j = -1;
		//		ft_printf("PATH %d: ", i);
//		while (e->data[e->nb_room - 1].path[i][++j] != -1)
//			ft_printf("**********%s ",e->data[e->data[e->nb_room - 1].path[i][j]].name);
//		ft_printf("\n");
//	}
//	ft_printf("\n-------------\n");
	if (algo_next(e))
		return (ft_error(e));
	sort_all_path(e, e->data[e->nb_room - 1].path);
	make_play(e);
//	dprintf(1, "poss %d is the best one, playable in %d turns\n", e->poss_to_play, e->play[0][0]);
//	j = -1;
//	while (e->play[++j])
//		dprintf(1, "%d coups %d ants on the path %d\n", e->play[j][0], e->play[j][1], j);
//	dprintf(1, "nb_path = %d\n", e->nb_path);
//	ft_printf("\n-------------\n");
//	printf("\n");
//	ft_print_dataname(e);
//	printf("\n");
	ft_printf("%s\n", e->save);
	print_inttab(e->data[e->nb_room - 1].path[e->all_path[0][0]]);
	move_ants(e, e->poss_to_play);
	//PRINT SOLUTIONS
	//free_env(&e);
	return (0);
}
