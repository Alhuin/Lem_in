/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_nbrs.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 15:59:14 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 15:50:57 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	nbrs_dip(t_ptf *s)
{
	if (s->conv == 'd' || s->conv == 'i')
	{
		if (s->size == 'H')
			s->arg = ft_itoa((char)va_arg(s->ap, int));
		else if (s->size == 'h')
			s->arg = ft_itoa((short)va_arg(s->ap, int));
		else if (s->size == 'l')
			s->arg = ft_itoa(va_arg(s->ap, long));
		else if (s->size == 'L')
			s->arg = ft_itoa(va_arg(s->ap, long long));
		else if (s->size == 'j')
			s->arg = ft_itoa(va_arg(s->ap, intmax_t));
		else if (s->size == 'z')
			s->arg = ft_itoa(va_arg(s->ap, size_t));
		else
			s->arg = ft_itoa(va_arg(s->ap, int));
	}
	else if (s->conv == 'D')
		s->arg = ft_itoa(va_arg(s->ap, long int));
	else if (s->conv == 'p')
		s->arg = ft_strjoin("0x", ft_itoabase((unsigned long)
					va_arg(s->ap, void *), "0123456789abcdef", 16), 2);
}

void	nbrs_uox_next(t_ptf *s, uintmax_t tmp)
{
	if (s->conv == 'x')
		s->arg = ft_itoabase(tmp, "0123456789abcdef", 16);
	else if (s->conv == 'X')
		s->arg = ft_itoabase(tmp, "0123456789ABCDEF", 16);
	else if (s->conv == 'o' || s->conv == 'O')
		s->arg = ft_itoabase(tmp, "0123456789", 8);
	else if (s->conv == 'u' || s->conv == 'U')
		s->arg = ft_itoabase(tmp, "0123456789", 10);
}

void	nbrs_uox(t_ptf *s)
{
	uintmax_t tmp;

	if (s->size == 'H')
		tmp = (unsigned char)va_arg(s->ap, int);
	else if (s->size == 'h')
		tmp = (unsigned short)va_arg(s->ap, int);
	else if (s->size == 'l' || s->conv == 'O' || s->conv == 'U')
		tmp = va_arg(s->ap, unsigned long);
	else if (s->size == 'L')
		tmp = va_arg(s->ap, unsigned long long);
	else if (s->size == 'j')
		tmp = va_arg(s->ap, uintmax_t);
	else if (s->size == 'z')
		tmp = va_arg(s->ap, size_t);
	else
		tmp = va_arg(s->ap, unsigned int);
	if (!tmp)
		s->arg_null += 1;
	nbrs_uox_next(s, tmp);
}

void	handle_nbrs(t_ptf *s)
{
	if (s->conv == 'd' || s->conv == 'i' || s->conv == 'D' || s->conv == 'p')
		nbrs_dip(s);
	else if (s->conv == 'u' || s->conv == 'U' || s->conv == 'o'
			|| s->conv == 'O' || s->conv == 'x' || s->conv == 'X')
		nbrs_uox(s);
	else if (s->conv == '%')
	{
		s->arg = ft_strnew(2);
		s->arg[0] = '%';
	}
}
