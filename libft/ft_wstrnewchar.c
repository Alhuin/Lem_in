/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrnewchar.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 20:18:05 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 18:35:24 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrnewchar(int size, wchar_t c)
{
	wchar_t		*str;
	int			i;

	i = 0;
	if (!(str = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	while (size--)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}
