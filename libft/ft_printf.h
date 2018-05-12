/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 09:24:21 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:49:45 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <locale.h>
# include "libft.h"

typedef struct	s_ptf
{
	va_list		ap;
	char		*str;
	size_t		i;
	char		buff[BUFF_SIZE];
	size_t		b;
	size_t		len;
	char		*option;
	int			wide;
	int			prec;
	char		size;
	char		conv;
	char		*arg;
	wchar_t		*warg;
	int			error;
	int			c_zero;
	int			arg_null;
}				t_ptf;

int				ft_printf(const char *restrict str, ...);
void			ft_saveoption(t_ptf *s);
void			ft_savewide(t_ptf *s);
void			ft_saveprec(t_ptf *s);
void			ft_savesize(t_ptf *s);
void			ft_saveconv(t_ptf *s);
void			ft_handle(t_ptf *s);
void			handle_strings(t_ptf *s);
void			handle_nbrs(t_ptf *s);
void			handle_size(t_ptf *s);
void			handle_prec_nbrs(t_ptf *s);
void			handle_prec_str(t_ptf *s);
void			handle_option(t_ptf *s);
void			handle_wide_nbr(t_ptf *s);
void			handle_wide_str(t_ptf *s);
void			handle_wide_wstr(t_ptf *s);
void			ft_display_buff(t_ptf *s);
void			ft_lstdelone(t_ptf **s);
void			ft_init_one(t_ptf *s);
void			ft_init(t_ptf *s);
void			ft_organise(t_ptf *s);
void			ft_display(t_ptf *s);

#endif
