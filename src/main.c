#include "../includes/lemin.h"

void		ft_diese(t_lem *e)
{
	if (!ft_strcmp(e->line, "##start"))
		e->start_end = 1;
	else if (!ft_strcmp(e->line, "##end"))
		e->start_end = 2;
}

int			ft_error(t_lem *e)
{
	(void)e;
	ft_printf("Error\n");
	//FREE STRUCT
	return (-1);
}

int			ft_parse(t_lem *e)
{
	char	**t;
	int		i;
	int		j;

	while (get_next_line(0, &e->line))
	{
		e->room = 0;
		if (e->line[0] == '#')
			ft_diese(e);
		else if (!e->stop)
		{
			e->stop++;
			e->nb_ants = ft_atoi(e->line);
			if (!ft_str_is_num(e->line) || e->nb_ants <= 0)
				return (-1);
		}
		else if ((t = ft_get_room(e)))
		{
			if (ft_check_room_name(e, t[0], 1) == -1)
			{
			//	dprintf(2, "t[0] = %s\n", t[0]);
				return (-1);
			}
			if (ft_check_room_coord(e, ft_atoi(t[1]), ft_atoi(t[2])) == -1)
				return (-1);
			if (ft_init_room(t[0], e, ft_atoi(t[1]), ft_atoi(t[2])) == -1)
				return (-1);
			ft_free_tmp(t);
		}
		else if (e->nb_room > 0 && (t = ft_get_links(e)))
		{
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
		}
		else
			return (-1);
		e->save = ft_strjoin(ft_strjoin(e->save, e->line, 2), "\n", 1);
	//	dprintf(2, "save = %s\n", e->save);
	}
	return (0);
}

int			ft_check_data(t_lem *e)
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
			start++;
		if (e->data[i].dist_e == 0)
			end++;
	}
	if (start != 1 || end != 1)
		return (-1);
	return (0);
}

int main(void)
{
	t_lem	*e;

	if (!(e = malloc(sizeof(t_lem))))
		return (ft_error(e));
	e->line = NULL;
	e->save = NULL;
	e->stop = 0;
	e->data = NULL;
	e->nb_room = 0;
	e->start_end = 0;
	e->total_nb_links = 0;
	e->error = 0;
	e->room = 0;
	e->start = 0;
	e->end = 0;

	if (ft_parse(e) == -1 || ft_check_data(e) == -1)
		return (ft_error(e));
		make_matrice(e);
	bfs(e, e->end);
	ft_printf("%s", e->save);
	//PRINT SOLUTIONS
	//FREE TOUT
	return (0);
}
