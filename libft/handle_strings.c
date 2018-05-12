/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_strings.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 13:35:42 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/03 11:15:19 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_w(t_ptf *s)
{
	int i;

	i = -1;
	while (s->warg[++i] != '\0')
	{
		if (s->warg[i] < 0 || s->warg[i] > 0x10FFFF
				|| ((s->warg[i] >= 0xD800) && (s->warg[i] <= 0xDFFF)))
			s->error = 1;
	}
}

void	handle_s(t_ptf *s)
{
	int i;

	i = -1;
	if (!(s->warg = ft_wstrdup(va_arg(s->ap, wchar_t *))))
		s->warg = ft_wstrdup(L"(null)");
	if (MB_CUR_MAX == 1)
	{
		while (s->warg[++i] != '\0')
		{
			if ((s->warg[i] > 127) && (s->warg[i] < 256))
				s->warg[i] = (char)s->warg[i];
			else if ((s->warg[i] < 1) || (s->warg[i] > 255))
			{
				if (i == s->prec)
				{
					s->warg = ft_wstrndup(s->warg, 0, i);
					break ;
				}
				s->error = 1;
				break ;
			}
		}
	}
	else
		check_w(s);
}

void	handle_c(t_ptf *s)
{
	int		i;
	wchar_t	wc;

	i = 0;
	wc = va_arg(s->ap, wchar_t);
	if (wc == 0 || wc == (int)NULL)
	{
		s->warg = ft_wstrnew(1);
		s->c_zero += 1;
	}
	else
	{
		s->warg = ft_wstrnew(2);
		s->warg[0] = wc;
		s->warg[1] = '\0';
	}
	if (MB_CUR_MAX == 1)
	{
		if ((s->warg[0] > 127) && (s->warg[0] < 256))
			s->warg[0] = (char)s->warg[0];
		else if ((s->warg[0] < 1) || (s->warg[0] > 255))
			s->error = 1;
	}
	else
		check_w(s);
}

void	handle_smallc(t_ptf *s)
{
	char	c;

	s->arg = ft_strnew(2);
	c = (char)va_arg(s->ap, int);
	if (c == 0 || c == (int)NULL)
	{
		s->arg = ft_strnew(1);
		s->c_zero += 1;
		ft_display_buff(s);
	}
	else
		s->arg[0] = c;
}

void	handle_strings(t_ptf *s)
{
	if (s->conv == 's' && s->size == 'l')
		s->conv = 'S';
	else if (s->conv == 'c' && s->size == 'l')
		s->conv = 'C';
	else if (s->conv == 's')
	{
		if (!(s->arg = ft_strdup(va_arg(s->ap, char *))))
			s->arg = ft_strdup("(null)");
	}
	else if (s->conv == 'c')
		handle_smallc(s);
	if (s->conv == 'S')
		handle_s(s);
	else if (s->conv == 'C')
		handle_c(s);
}
