/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 18:19:40 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:28:35 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_calc_final(t_fdf *s)
{
	int i;
	int j;
	int x;
	int y;

	j = 0;
	x = s->x_max;
	y = s->y_max;
	while (y-- > 0)
	{
		i = 0;
		x = s->x_max;
		while (x > 0)
		{
			s->map[j][i].x_f = (s->map[j][i].x * cos(s->angle_y) +
				s->map[j][i].y * cos(s->angle_y + s->angle_x) + s->map[j][i].z
				* cos(s->angle_y - s->angle_x)) * s->zoom + s->move_x;
			s->map[j][i].y_f = (s->map[j][i].x * sin(s->angle_y) +
				s->map[j][i].y * sin(s->angle_y + s->angle_x) + s->map[j][i].z
				* sin(s->angle_y - s->angle_x)) * s->zoom + s->move_y;
			i++;
			x--;
		}
		j++;
	}
}

void	ft_parse_calc(t_fdf *s, int i, char *str)
{
	s->map[s->y_max][i].x = i;
	s->map[s->y_max][i].y = s->y_max;
	s->map[s->y_max][i].z = ft_atoi(str);
}

void	ft_parse_map(t_fdf *s, char *line, int i)
{
	char	**str;

	while (line[i] != '\0')
	{
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9')
				|| line[i] == '-' || line[i] == 'x' || line[i] == ','
				|| (line[i] >= 'A' && line[i] <= 'F'))
			i++;
		else
		{
			s->error = 1;
			break ;
		}
	}
	str = ft_strsplit(line, ' ');
	i = 0;
	s->map[s->y_max] = malloc(sizeof(t_pos) * (s->x_max + 1));
	while (str[i] && s->error == 0)
	{
		ft_parse_calc(s, i, str[i]);
		free(str[i++]);
	}
	free(str);
	if (i != s->x_max)
		s->error = 1;
}

int		ft_reader_next(t_fdf *s, int fd, int f, char *line)
{
	while (get_next_line(fd, &line) == 1)
	{
		if (f == 1)
		{
			s->x_max = ft_countwords(line, ' ');
			s->map = (t_pos **)malloc(sizeof(t_pos*) * 2);
			f = 0;
			ft_parse_map(s, line, 0);
		}
		else if (s->x_max != ft_countwords(line, ' ') || s->error == 1)
		{
			s->error = 1;
			break ;
		}
		else
		{
			s->map = (t_pos **)ft_realloc(s->map, (sizeof(t_pos*) * (s->y_max
						+ 1)), sizeof(t_pos*) * (s->y_max + 2));
			ft_parse_map(s, line, 0);
		}
		s->y_max++;
		free(line);
	}
	return (f);
}

void	ft_reader(t_fdf *s, char *file_name)
{
	int		fd;
	int		f;
	char	*line;

	f = 1;
	line = NULL;
	s->x_max = 0;
	s->y_max = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("No file %s\n", file_name);
		s->error = 2;
		return ;
	}
	f = ft_reader_next(s, fd, f, line);
	if (f == 1)
	{
		ft_printf("No data found.\n");
		s->error = 2;
		return ;
	}
	s->map[s->y_max] = NULL;
	close(fd);
}
