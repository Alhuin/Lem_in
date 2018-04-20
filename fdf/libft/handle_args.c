/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_args.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 13:24:45 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 15:39:06 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_nbr(t_ptf *s)
{
	int len_prec;

	handle_nbrs(s);
	if (s->arg[0] == '-')
		len_prec = (int)ft_strlen(s->arg) - 1;
	else
		len_prec = (int)ft_strlen(s->arg);
	if (s->prec == 0 && s->arg[0] == '0' && s->arg[1] == '\0'
			&& s->conv != '%')
		s->arg = ft_strnew(1);
	else if (s->prec > 0 && (s->prec > len_prec) && s->conv != '%')
		handle_prec_nbrs(s);
	if (s->option != NULL && s->conv != '%')
		handle_option(s);
	if (s->wide != -1 && (s->wide > (int)ft_strlen(s->arg)))
		handle_wide_nbr(s);
}

void	ft_handle_str(t_ptf *s)
{
	handle_strings(s);
	if (s->prec >= 0)
		handle_prec_str(s);
	if (s->wide > 0)
	{
		if ((s->conv == 's' || s->conv == 'c')
				&& (s->wide > (int)ft_strlen(s->arg)))
			handle_wide_str(s);
		else if (s->warg && (s->wide > (int)ft_wstrlen(s->warg)))
			handle_wide_wstr(s);
	}
}

void	ft_handle(t_ptf *s)
{
	if (s->conv == 's' || s->conv == 'S' || s->conv == 'c'
			|| s->conv == 'C')
		ft_handle_str(s);
	else if (s->conv == 'd' || s->conv == 'i' || s->conv == 'D' ||
			s->conv == 'p' || s->conv == 'x' || s->conv == 'X'
			|| s->conv == 'o' || s->conv == 'O' || s->conv == 'u' ||
			s->conv == 'U' || s->conv == '%')
		ft_handle_nbr(s);
}
