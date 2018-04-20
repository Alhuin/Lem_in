/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 15:54:58 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:20:36 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_fdf *s)
{
	int i;
	int j;
	int x;
	int y;

	j = 0;
	x = s->x_max;
	y = s->y_max;
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	while (y > 0)
	{
		i = 0;
		x = s->x_max;
		while (x > 0)
		{
			if (s->map[j][i].x < s->x_max - 1)
				ft_bresenham(s, &s->map[j][i], &s->map[j][i + 1]);
			if (s->map[j][i].y < s->y_max - 1)
				ft_bresenham(s, &s->map[j][i], &s->map[j + 1][i]);
			i++;
			x--;
		}
		j++;
		y--;
	}
}

void	use_key(int key, t_fdf *s)
{
	if (key == KEY_PAD_ADD)
		s->zoom++;
	if (key == KEY_PAD_SUB)
		s->zoom--;
	if (key == KEY_UP)
		s->move_y -= 10;
	if (key == KEY_DOWN)
		s->move_y += 10;
	if (key == KEY_RIGHT)
		s->move_x += 10;
	if (key == KEY_LEFT)
		s->move_x -= 10;
	if (key == KEY_W)
		s->angle_y--;
	if (key == KEY_S)
		s->angle_y++;
	if (key == KEY_A)
		s->angle_x++;
	if (key == KEY_D)
		s->angle_x--;
}

int		deal_key(int key, t_fdf *s)
{
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB || key == KEY_UP
			|| key == KEY_DOWN || key == KEY_RIGHT || key == KEY_LEFT
			|| key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
	{
		use_key(key, s);
		ft_calc_final(s);
		draw(s);
	}
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(s->mlx_ptr, s->win_ptr);
		ft_free_fdf(s);
		free(s);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_initialization(t_fdf *s)
{
	s->error = 0;
	s->zoom = 10;
	s->move_x = 1;
	s->move_y = 1;
	s->angle_y = 0;
	s->angle_x = 120;
}

int		main(int ac, char **av)
{
	t_fdf	*s;

	s = NULL;
	if (ac == 2)
	{
		s = malloc(sizeof(t_ptf));
		ft_initialization(s);
		ft_reader(s, av[1]);
		ft_calc_final(s);
		if (s->error == 1)
		{
			ft_printf("Invalid Map\n");
			return (0);
		}
		else if (s->error == 2)
			return (0);
		s->mlx_ptr = mlx_init();
		s->win_ptr = mlx_new_window(s->mlx_ptr, WIN_X, WIN_Y, "FDF-BRO | :-{D");
		draw(s);
		mlx_key_hook(s->win_ptr, deal_key, s);
		mlx_loop(s->mlx_ptr);
	}
	else
		ft_printf("Usage : ./fdf <filename>\n");
	return (0);
}
