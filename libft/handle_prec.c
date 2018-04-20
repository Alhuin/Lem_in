/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_prec.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 16:54:41 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 15:51:16 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_prec_nbrs(t_ptf *s)
{
	size_t	len;
	int		neg;
	char	*tmp;
	int		i;
	int		diff;

	i = 0;
	neg = 0;
	if (s->arg[0] == '-')
		len = ft_strlen(s->arg) - 1;
	else
		len = ft_strlen(s->arg);
	diff = s->prec - len;
	if (diff)
	{
		if (s->arg[0] == '-')
			neg = 1;
		tmp = ft_strnewchar(diff, '0');
		if (!neg)
			s->arg = ft_strjoin(tmp, s->arg, 3);
		else
			s->arg = ft_strjoin(ft_strjoin("-", tmp, 2),
					ft_strndup(s->arg, 1, s->prec), 3);
	}
}

void	handle_prec_str(t_ptf *s)
{
	int		len;

	len = 0;
	if (s->arg)
		len = ft_strlen(s->arg);
	else if (s->warg)
		len = ft_wstrlen(s->warg);
	if (s->prec < len)
	{
		if (s->arg)
		{
			s->arg = ft_strndup(s->arg, 0, s->prec);
		}
		else if (s->warg)
			s->warg = ft_wstrndup(s->warg, 0, s->prec);
	}
}
