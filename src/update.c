/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 00:16:52 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 14:14:22 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		update_add_manage(t_lem *e, int i, int len)
{
	int		y;

	if (e->data[i].path == NULL && len > 1)
	{
		if (!(e->data[i].path = malloc(sizeof(int*) * len)))
			return (-1);
		e->data[i].nb_path += len;
		y = -1;
		while (++y <  e->data[i].nb_path)
			e->data[i].path[y] = NULL;
		e->data[i].nb_path = len;
	}
	else if (e->data[i].path == NULL)
	{
		if (!(e->data[i].path = malloc(sizeof(int*))))
			return (-1);
		e->data[i].nb_path++;
		e->data[i].path[0] = NULL;
	}
	else
	{
		if (!(e->data[i].path = ft_realloc(e->data[i].path, sizeof(int*) *
						e->data[i].nb_path, sizeof(int*) * (len
						+ e->data[i].nb_path))))
			return (-1);
		e->data[i].nb_path += len;
	}
	return (0);

}

int		update_add_copy(t_lem *e, int **ret, int i, int len, int ref)
{
	int		k;
	int		l;

	if (e->data[i].nb_path == 1 && len > e->data[i].nb_path)
		k = 0;
	else
		k = e->data[i].nb_path - len;
	l = 0;
	while (k < e->data[i].nb_path)
	{
		e->data[i].path[k] = ft_inttabjoin(ret[l],
				e->data[i].path[k]);
		e->data[i].path[k] = ft_inttabadd(e->data[i].path[k], ref);
		k++;
		l++;
	}
	return (0);
}


int		intintab(int *s1, int k)
{
	int	i;

	i = -1;
	while(s1[++i] != -1)
	{
		if (s1[i] == k)
			return (-1);
	}
	return (0);
}

int		inttab_cmp(int *s1, int *s2, int ref)
{
	int	i;

	i = 0;
//	print_inttab(s1, "intabcmp s1 ");
//	print_inttab(s2, "intabcmp s2 ");
	while (s1[i] == s2[i] && s1[i] != -1 && s2[i] != -1)
		i++;
//	printf("return = %d\n\n", s1[i] - s2[i]);
	return (s1[i] - s2[i] + (ref + 1));
}

int		**prepare_path_add(int *tmp, int **path)
{
	int		**ret;
	int		len;
	int		i;
	int		j;

	len = ft_inttablen(tmp);
	ret = malloc(sizeof(int*) * len);
	i = -1;
	while(++i < len)
	{
		ret[i] = malloc(sizeof(int) * (ft_inttablen(path[tmp[i]]) + 1));
		j = -1;
		while (path[tmp[i]][++j] != -1)
			ret[i][j] = path[tmp[i]][j];
		ret[i][j] = -1;
	}
	return (ret);
}

int		compare_update(t_lem *e, int i, int ref)
{
	int		l;
	int		k;
	int		y;
	int		err;
	int		tmp[e->data[ref].nb_path + 1];
	int		**ret;

	l = -1;
	y = -1;
	while (++l < e->data[ref].nb_path + 1)
		tmp[l] = -1;
	l = -1;
	while (++l < e->data[ref].nb_path)
	{
		k = -1;
		err = 0;
		if (intintab(e->data[ref].path[l], i) == -1)
		{
		//	print_inttab(e->data[ref].path[l], "E1 ");
			continue ;
		}
		while (++k < e->data[i].nb_path)
		{
			if (!(inttab_cmp(e->data[ref].path[l], e->data[i].path[k], ref)))
			{
			//	printf("E2\n");
				err = 1;
				break ;
			}
		}
		if (err == 0)
			tmp[++y] = l;
	}
//	print_inttab(tmp, "TMP ");
	if (ft_inttablen(tmp))
	{
	//	print_inttab(e->data[ref].path[tmp[0]], "AJOUT ");
		ret = prepare_path_add(tmp, e->data[ref].path);
//		l = -1;
	//	while (++l < ft_inttablen(tmp))
	//		print_inttab(ret[l], "RET ");
		//Ajouter ret au path existant
		update_add_manage(e, i, ft_inttablen(tmp));
		update_add_copy(e, ret, i, ft_inttablen(tmp), ref);
	}
//	printf("\n");
	return (0);
}

int		update_path(t_lem *e, int i, int ref)
{
	int	j;

	j = -1;

	compare_update(e, i, ref);

	while (++j < e->data[i].nb_links)
	{
		if (e->data[i].floor <= e->data[e->data[i].links[j]].floor)
		{
			compare_update(e, e->data[i].links[j], i);
		}
	}

//	printf("\n");
	return (0);
}
