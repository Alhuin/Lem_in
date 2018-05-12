/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_wide_str.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 18:35:16 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:52:22 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_wide_str(t_ptf *s)
{
	int		len;
	char	*tmp;
	int		i;

	if (s->conv == 'c' && s->arg[0] == '\0')
		len = s->wide - ft_strlen(s->arg) - 1;
	else
		len = s->wide - ft_strlen(s->arg);
	if (s->option && s->option[0] == '-')
	{
		if (s->arg[0] == '\0')
		{
			i = 0;
			tmp = ft_strnewchar(len, ' ');
			while (tmp[i])
				s->buff[s->b++] = tmp[i++];
			free(tmp);
		}
		else
			s->arg = ft_strjoin(s->arg, ft_strnewchar(len, ' '), 3);
	}
	else
		s->arg = ft_strjoin(ft_strnewchar(len, ' '), s->arg, 3);
}

void	handle_wide_wstr(t_ptf *s)
{
	int		len;

	len = s->wide - ft_wstrlen(s->warg);
	if (s->option && s->option[0] == '-')
		s->warg = ft_wstrjoin(s->warg, ft_wstrnewchar(len, L' '), 3);
	else
		s->warg = ft_wstrjoin(ft_wstrnewchar(len, L' '), s->warg, 3);
}
