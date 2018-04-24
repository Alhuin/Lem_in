/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoabase.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/06 17:07:04 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:47:38 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_countnb(uintmax_t nbr, int baselen)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	else
	{
		while (nbr)
		{
			nbr /= baselen;
			i++;
		}
		return (i);
	}
}

char		*ft_itoabase(uintmax_t nbr, char *base, int baselen)
{
	int		tmp;
	int		i;
	char	*ret;

	tmp = 0;
	i = 0;
	if ((ret = ft_strnew(ft_countnb(nbr, baselen))) == NULL)
		return (NULL);
	while (nbr != 0 || i == 0)
	{
		tmp = nbr % baselen;
		tmp = (tmp < 0) ? -tmp : tmp;
		ret[i] = base[tmp];
		nbr /= baselen;
		i++;
	}
	ret[i] = '\0';
	ft_strrev(ret);
	return (ret);
}
