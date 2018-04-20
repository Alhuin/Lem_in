/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 17:12:54 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 17:12:54 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle == '\0')
		return ((char*)haystack);
	if (!needle)
		return ((char *)haystack);
	len = ft_strlen(needle);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, len) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
