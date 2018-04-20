/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_partlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/07 18:13:03 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/07 18:15:11 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_partlen(char *str, int i, char *comp)
{
	int	j;
	int	f;
	int	ret;

	ret = 0;
	f = 1;
	while (f)
	{
		j = 0;
		f = 0;
		while (comp[j] != '\0')
		{
			if (str[i] == comp[j])
			{
				f = 1;
				ret++;
			}
			j++;
		}
		i++;
	}
	return (ret);
}
