/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_wide.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 18:35:16 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 16:03:00 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	wide_nbr_next(t_ptf *s, int len)
{
	char *tmp;

	tmp = ft_strnewchar(len, '0');
	if (s->arg[0] == '-')
		s->arg = ft_strjoin(ft_strjoin("-", tmp, 2),
				ft_strndup(s->arg, 1, len), 3);
	else if (s->arg[0] == '+')
		s->arg = ft_strjoin(ft_strjoin("+", tmp, 2),
				ft_strndup(s->arg, 1, len), 3);
}

void	wide_nbr(t_ptf *s, int len, int opt_z, int opt_minus)
{
	char	*tmp;

	if ((opt_z && s->prec < 1 && opt_minus == 0) || (opt_z && s->conv == '%'))
	{
		if (s->arg[0] != '-' && s->arg[0] != '+')
		{
			if (s->arg[0] == ' ')
			{
				tmp = ft_strnewchar(len, '0');
				s->arg = ft_strjoin(ft_strjoin(" ", tmp, 2),
						ft_strndup(s->arg, 1, len), 3);
			}
			else
				s->arg = ft_strjoin(ft_strnewchar(len, '0'), s->arg, 3);
		}
		else
			wide_nbr_next(s, len);
		return ;
	}
	if (opt_minus)
		s->arg = ft_strjoin(s->arg, ft_strnewchar(len, ' '), 3);
	else
		s->arg = ft_strjoin(ft_strnewchar(len, ' '), s->arg, 3);
}

void	wide_x(t_ptf *s, int len)
{
	char	*tmp;

	tmp = ft_strnewchar(len, '0');
	if (s->arg_null)
	{
		s->arg = ft_strjoin(ft_strnewchar(len, '0'), s->arg, 3);
		free(tmp);
	}
	else if (s->conv == 'x')
		s->arg = ft_strjoin(ft_strjoin("0x", tmp, 2),
				ft_strndup(s->arg, 2, len), 3);
	else if (s->conv == 'X')
		s->arg = ft_strjoin(ft_strjoin("0X", tmp, 2),
				ft_strndup(s->arg, 2, len), 3);
}

void	wide_nbr_xo(t_ptf *s, int opt_z, int opt_minus, int opt_hex)
{
	int		len;

	len = s->wide - ft_strlen(s->arg);
	if (opt_z && s->prec < 1 && opt_minus == 0 && opt_hex == 0
			&& s->conv != 'O')
	{
		s->arg = ft_strjoin(ft_strnewchar(len, '0'), s->arg, 3);
		return ;
	}
	else if (opt_z && s->prec < 1 && opt_minus == 0 && s->conv == 'O'
			&& s->arg[0] == '0' && s->arg[1] == '\0')
	{
		s->arg = ft_strjoin(ft_strnewchar(len, '0'), s->arg, 3);
		return ;
	}
	else if (opt_z && s->prec < 0 && opt_minus == 0
			&& s->conv != 'O' && s->conv != 'o')
	{
		wide_x(s, len);
		return ;
	}
	if (opt_minus)
		s->arg = ft_strjoin(s->arg, ft_strnewchar(len, ' '), 3);
	else
		s->arg = ft_strjoin(ft_strnewchar(len, ' '), s->arg, 3);
}

void	handle_wide_nbr(t_ptf *s)
{
	int		len;
	int		i;
	int		opt_minus;
	int		opt_z;
	int		opt_hex;

	i = -1;
	opt_minus = 0;
	opt_z = 0;
	opt_hex = 0;
	if (!(len = s->wide - ft_strlen(s->arg)))
		return ;
	while (s->option && s->option[++i])
	{
		if (s->option[i] == '-')
			opt_minus++;
		if (s->option[i] == '0')
			opt_z++;
		if (s->option[i] == '#')
			opt_hex++;
	}
	if (s->conv == 'x' || s->conv == 'X' || s->conv == 'o' || s->conv == 'O')
		wide_nbr_xo(s, opt_z, opt_minus, opt_hex);
	else
		wide_nbr(s, len, opt_z, opt_minus);
}
