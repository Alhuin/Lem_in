/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 14:01:58 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 14:19:50 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_m_size(t_flr *box)
{
	int	i;

	i = 0;
	while (ft_isalpha(box->line[i]))
	{
		box->line[i] = ' ';
		i++;
	}
	box->map_y = ft_atoi(box->line);
	i++;
	while (ft_isdigit(box->line[i]))
	{
		box->line[i] = ' ';
		i++;
	}
	box->map_x = ft_atoi(box->line);
}

void	get_p_size(t_flr *box)
{
	int	i;

	i = 0;
	while (ft_isalpha(box->line[i]))
	{
		box->line[i] = ' ';
		i++;
	}
	box->piece_y = ft_atoi(box->line);
	i++;
	while (ft_isdigit(box->line[i]))
	{
		box->line[i] = ' ';
		i++;
	}
	box->piece_x = ft_atoi(box->line);
}

void	*get_map(t_flr *box)
{
	int	j;

	j = 0;
	get_next_line(0, &box->line);
	ft_strdel(&box->line);
	if (!(box->map = (char**)malloc(sizeof(char *) * box->map_y + 1)))
		return (NULL);
	while (j < box->map_y)
	{
		get_next_line(0, &box->line);
		box->map[j] = ft_strdup(&box->line[4]);
		ft_strdel(&box->line);
		j++;
	}
	box->map[j] = NULL;
	return (0);
}

void	*get_piece(t_flr *box)
{
	int	j;

	j = 0;
	if (!(box->piece = (char**)malloc(sizeof(char*) * box->piece_y + 1)))
		return (NULL);
	while (j < box->piece_y)
	{
		get_next_line(0, &box->line);
		box->piece[j] = ft_strdup(box->line);
		ft_strdel(&box->line);
		j++;
	}
	box->piece[j] = NULL;
	return (0);
}

int		big_loop(t_flr *box)
{
	while (get_next_line(0, &box->line) > 0)
	{
		if (!ft_strncmp(box->line, "Plateau", 7))
		{
			get_m_size(box);
			ft_strdel(&box->line);
			get_map(box);
		}
		else if (!ft_strncmp(box->line, "Piece", 5))
		{
			get_p_size(box);
			ft_strdel(&box->line);
			get_piece(box);
			return (1);
		}
		else
			ft_strdel(&box->line);
	}
	return (0);
}
