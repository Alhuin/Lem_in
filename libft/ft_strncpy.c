/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:53 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:53 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *strdst;

	strdst = dst;
	while (*src != '\0' && len > 0)
	{
		*strdst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*strdst++ = '\0';
		len--;
	}
	return (dst);
}
