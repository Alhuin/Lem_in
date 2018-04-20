/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/07 11:48:12 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 16:51:00 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_display_buff(t_ptf *s)
{
	if (s->b > 0)
	{
		s->len += ft_strlen(s->buff);
		write(1, &s->buff, ft_strlen(s->buff));
		ft_bzero(s->buff, BUFF_SIZE);
		s->b = 0;
	}
}

void		ft_display_warg(t_ptf *s)
{
	if (s->b)
		ft_display_buff(s);
	s->len += ft_wstrlen(s->warg);
	ft_putwstr(s->warg);
	if (s->c_zero)
	{
		ft_putchar('\0');
		s->len += 1;
	}
}

void		ft_display(t_ptf *s)
{
	if (s->error)
		return ;
	if (s->arg)
	{
		if (s->b && !s->c_zero)
			ft_display_buff(s);
		s->len += ft_strlen(s->arg);
		write(1, s->arg, ft_strlen(s->arg));
		if (s->c_zero)
		{
			ft_putchar('\0');
			s->len += 1;
		}
	}
	else if (s->warg)
		ft_display_warg(s);
}

void		ft_begin(t_ptf *s)
{
	ft_bzero(s->buff, BUFF_SIZE);
	ft_init_one(s);
	while (s->str[s->i] != '\0' && s->str)
	{
		ft_init(s);
		if (s->str[s->i] == '%')
		{
			s->i++;
			ft_organise(s);
			if (s->error)
				return ;
		}
		else
		{
			s->buff[s->b++] = s->str[s->i++];
			if (s->b == BUFF_SIZE - 1)
				ft_display_buff(s);
		}
	}
	ft_display_buff(s);
	ft_init(s);
}

int			ft_printf(const char *restrict str, ...)
{
	t_ptf	*s;
	int		ret;

	s = malloc(sizeof(t_ptf));
	s->i = 0;
	s->b = 0;
	s->len = 0;
	s->error = 0;
	s->str = (char *)str;
	va_start(s->ap, str);
	ft_begin(s);
	va_end(s->ap);
	ret = s->len;
	if (s->error)
	{
		if (s->c_zero)
			ft_putchar('\0');
		ft_init(s);
		free(s);
		return (-1);
	}
	free(s);
	return (ret);
}
