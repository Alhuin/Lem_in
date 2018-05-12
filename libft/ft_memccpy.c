/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:46 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:46 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *strdst;
	unsigned char *strsrc;

	strdst = (unsigned char*)dst;
	strsrc = (unsigned char*)src;
	while (n--)
	{
		if (*strsrc == (unsigned char)c)
		{
			*strdst++ = *strsrc++;
			return (strdst);
		}
		*strdst++ = *strsrc++;
	}
	return (NULL);
}
