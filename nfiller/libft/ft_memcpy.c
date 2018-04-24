/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:47 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 17:25:25 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*strcdst;
	const char	*strsrc;
	int			i;

	i = 0;
	strcdst = dst;
	strsrc = src;
	while (n--)
	{
		strcdst[i] = strsrc[i];
		i++;
	}
	return (dst);
}
