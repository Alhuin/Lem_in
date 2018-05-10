/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 18:07:28 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/10 12:14:06 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_result(t_gnl *lst)
{
	if (lst->ret > 0)
	{
		lst->buff[lst->ret] = '\0';
		if (!(lst->line = ft_strjoin(lst->text, lst->buff, 0)))
			return (-1);
		free(lst->text);
		lst->text = lst->line;
		lst->tmp = ft_strchr(lst->text, '\n');
	}
	else if (lst->ret == 0)
	{
		lst->tmp = ft_strchr(lst->text, '\0');
		if (ft_strequ((lst->tmp), lst->text))
			return (0);
	}
	else if (lst->ret < 0)
		return (-2);
	return (1);
}

static char		*ft_textinit(char *tmp)
{
	char	*text;

	if (tmp == NULL)
		return (NULL);
	text = ft_strnew(ft_strlen(tmp) + 1);
	ft_strcpy(text, tmp);
	return (text);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	lst;

	lst.buff = ft_strnew(BUFF_GNL + 1);
	if (!lst.text && (lst.text = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	lst.tmp = ft_strchr(lst.text, '\n');
	while (lst.tmp == NULL)
	{
		lst.ret = read(fd, lst.buff, BUFF_GNL);
		if ((lst.result = ft_result(&lst)) < 1)
			return (lst.result);
	}
	if (!(*line = ft_strsub(lst.text, 0, lst.tmp - lst.text)))
		return (-1);
	lst.tmp = ft_strdup(lst.tmp + 1);
	ft_strdel(&lst.text);
	lst.text = ft_textinit(lst.tmp);
	free(lst.tmp);
	free(lst.buff);
	return (1);
}
