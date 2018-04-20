#include "lemin.h"

int		check_room_name(char *str, t_lem *s)
{
	int		i;

	i = 0;
	if (!ft_strncmp(str, "L", 1))
		return (1);
	dprintf(2, "check room nb_room = %d\n", s->nb_room);
	while(i <= s->nb_room)
	{
		dprintf(2, "i = %d\n", i);
		if (!ft_strcmp(str, s->data[i].name))
			return (1);
		i++;
	}
	return (0);
}

char	**ft_links(char *line, t_lem *s)
{
	char	**str;
	int		i;

	dprintf(2, "ft_links\n");
	i = 0;
	str = ft_strsplit(line, '-');
	while (str[i])
	{
		if (!check_room_name(str[i] ,s))
			return (NULL);
		i++;
	}
	if (i != 2)
		return (NULL);
	return (str);
}

char		**ft_room(char *line, t_lem *s)
{
	char	**str;
	int		i;

	i = 1;
	str = ft_strsplit(line, ' ');
	dprintf(2, "check line %s\ncheck str %s\n", line, str[0]);
	if (check_room_name(str[0], s))
		return (NULL);
	while (str[i])
	{
		if (!ft_str_is_num(str[i]))
		{
			s->error = 1;
			return (NULL);
		}
		i++;
	}
	if (i != 3)
	{
		s->error = 1;
		return (NULL);
	}
	return (str);
}

void	ft_diese(char *line, t_lem *s)
{
		if (!ft_strcmp(line, "##start"))
			s->start_end = 1;
		else if (!ft_strcmp(line, "##end"))
			s->start_end = 2;
}

int		ft_parsing(t_lem *s)
{
	char	**str;
	char	*line;
	int		stop;
	int		i;
	int		j;

	stop = 0;
	while (get_next_line(0, &line) == 1)
	{
		str = NULL;
		dprintf(2, "line : %s\n", line);
		if (!ft_strncmp(line, "#", 1))
			ft_diese(line, s);
		else if (!stop)
		{
			s->nb_ants = ft_atoi(line);
			dprintf(2, "nb ants = %d\n", s->nb_ants);
			if (!ft_str_is_num(line) || s->nb_ants <= 0)
			{
				s->error = 1;
				return (1);
			}
		}
		else if ((str = ft_room(line, s)))
		{
			i = 0;
			s->nb_room++;
			dprintf(2, "room nb -> %d\n", s->nb_room);
			if (s->nb_room > 1)
				ft_realloc(s->data, sizeof(t_room) * s->nb_room, sizeof(t_room) * (s->nb_room + 1));
			s->data[s->nb_room].name = ft_strdup(str[0]);
			if (s->start_end == 1)
				s->data[s->nb_room].dist_s = 0;
			else
				s->data[s->nb_room].dist_s = -1;
			if (s->start_end == 2)
				s->data[s->nb_room].dist_end = 0;
			else
				s->data[s->nb_room].dist_end = -1;
			s->data[s->nb_room].nb_links = 0;
			dprintf(2, "room: name-%s | nb_links-%d | dist_s-%d | dist_end-%d\n", s->data[s->nb_room].name, s->data[s->nb_room].nb_links, s->data[s->nb_room].dist_s, s->data[s->nb_room].dist_end);
			s->start_end = 0;
		}
		else if ((str = ft_links(line, s)))
		{
			i = 0;
			j = 0;
			while (s->data[i].name != str[0])
				i++;
			while (s->data[j].name != str[1])
				j++;
			if (s->data[i].links == NULL)
			{
				s->data[i].links = malloc(sizeof(int) * 2);
				s->data[i].links[0] = i;
				s->data[i].links[1] = '\0';
				s->data->nb_links++;
			}
			else
			{
				s->data[i].links = ft_realloc(s->data[i].links, s->data->nb_links, s->data->nb_links + 1);
				s->data->nb_links++;
			}
			if (s->data[j].links == NULL)
			{
				s->data[j].links = malloc(sizeof(int) * 2);
				s->data[j].links[0] = j;
				s->data[j].links[1] = '\0';
			}
			else
			{
				s->data[j].links = ft_realloc(s->data[j].links, s->data->nb_links, s->data->nb_links + 1);
				s->data->nb_links++;
			}
			s->total_nb_links++;
		}
		else
		{
			dprintf(2, "Last error\n");
			return (1);
		}
		if (s->error == 1)
			return (1);
		stop++;
		i = 0;
		if (**str)
		{
			while(str[i])
			{
				if(*str[i])
					ft_strdel(&str[i]);
			}
			free(str);
		}
		free(line);
	}
	return (0);
}

void	ft_init_room(t_lem *s)
{
	s->data[s->nb_room + 1].name = NULL;
	s->data[s->nb_room + 1].links = NULL;
	s->data[s->nb_room + 1].nb_links = 0;
	s->data[s->nb_room + 1].dist_s = -1;
	s->data[s->nb_room + 1].dist_end = -1;
}

void	ft_init_lem(t_lem *s)
{
	s->nb_ants = 0;
	s->nb_room = -1;
	s->total_nb_links = 0;
	s->error = 0;
	s->equiv = NULL;
	s->start_end = 0;
	s->data = (t_room*)malloc(sizeof(t_room));
	ft_init_room(s);
}

void	ft_recap(t_lem *s)
{
	int		i;
	int		j;

	i = 0;
	ft_printf("%d\n", s->nb_ants);
	while (i < s->nb_room)
	{
		if (s->data[i].dist_s == 0)
			ft_printf("##start\n");
		else if (s->data[i].dist_end == 0)
			ft_printf("##end\n");
		ft_printf("%s\n", s->data[i].name);
		i++;
	}
	i = 0;
	while (i < s->nb_room)
	{
		j = 0;
		while (s->data[i].links[j])
		{
			printf("%d ", s->data[i].links[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int		main(void)
{
	t_lem	*s;

	s = (t_lem*)malloc(sizeof(t_lem));
	ft_init_lem(s);
	if (ft_parsing(s))
	{
		ft_printf("ERROR\n");
		return (0);
	}
	ft_recap(s);
	return (0);
}
