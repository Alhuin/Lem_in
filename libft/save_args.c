/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   save_args.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 15:31:06 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 16:59:46 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_saveoption(t_ptf *s)
{
	int	len;
	int	j;

	j = 0;
	len = ft_partlen(s->str, s->i, "#0-+ ");
	if (!len || !(s->option = ft_strnew(len + 1)))
		s->option = NULL;
	else
	{
		while (len)
		{
			s->option[j] = s->str[s->i];
			j++;
			s->i++;
			len--;
		}
		s->option[j] = '\0';
	}
}

void	ft_savewide(t_ptf *s)
{
	int		len;
	int		j;
	char	*nb;

	j = 0;
	len = ft_partlen(s->str, s->i, "0123456789");
	if (!len || !(nb = ft_strnew(len + 1)))
		s->wide = -1;
	else
	{
		while (len)
		{
			nb[j] = s->str[s->i];
			j++;
			s->i++;
			len--;
		}
		nb[j] = '\0';
		s->wide = ft_atoi(nb);
		free(nb);
	}
}

void	ft_saveprec(t_ptf *s)
{
	int		len;
	int		j;
	char	*nb;

	j = 0;
	if (s->str[s->i] == '.')
	{
		s->i++;
		len = ft_partlen(s->str, s->i, "0123456789");
		if (!len || !(nb = ft_strnew(len + 1)))
			s->prec = 0;
		else
		{
			while (len--)
			{
				nb[j++] = s->str[s->i];
				s->i++;
			}
			nb[j] = '\0';
			s->prec = ft_atoi(nb);
			free(nb);
		}
	}
	else
		s->prec = -1;
}

void	ft_savesize(t_ptf *s)
{
	int	len;

	len = ft_partlen(s->str, s->i, "hljz");
	if (len == 1)
		s->size = s->str[s->i++];
	else if (s->str[s->i] == 'l' && s->str[s->i + 1] == 'l')
	{
		s->size = 'L';
		s->i += 2;
	}
	else if (s->str[s->i] == 'h' && s->str[s->i + 1] == 'h')
	{
		s->size = 'H';
		s->i += 2;
	}
	else
		s->size = 0;
}

void	ft_saveconv(t_ptf *s)
{
	int	len;
	int	j;

	j = 0;
	len = ft_partlen(s->str, s->i, "sSpdDioOuUxXcC%");
	if (!len)
		s->conv = 0;
	else
	{
		s->conv = s->str[s->i];
		s->i++;
	}
}
