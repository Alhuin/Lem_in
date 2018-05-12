/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrndup.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:20:17 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:49:17 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrndup(wchar_t *str, size_t j, size_t n)
{
	wchar_t		*ret;
	size_t		i;

	i = 0;
	if (!(ret = ft_wstrnew(n + 1)))
		return (NULL);
	while (str[j] != '\0' && (n >= (size_t)ft_wcharlen(str[j])))
	{
		ret[i] = str[j];
		n -= (size_t)ft_wcharlen(str[j]);
		i++;
		j++;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}
