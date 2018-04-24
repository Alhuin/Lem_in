/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoning.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 07:23:18 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 19:11:20 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_zone_move_one(t_flr *box, int e, int f)
{
	int a;
	int b;
	int c;
	int d;

	a = box->map_x / 4;
	b = box->map_x / 2;
	c = (3 * box->map_x) / 4;
	d = box->map_y / 4;
	e = box->map_y / 2;
	f = (3 * box->map_y) / 4;
	if (box->zone_me == 1 && box->zone_him == 1)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? c : b,
				(box->odd % 2 == 0) ? b : 0);
	if (box->zone_me == 1 && box->zone_him == 2)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? c : 0,
				(box->odd % 2 == 0) ? b : box->map_y);
	if (box->zone_me == 1 && box->zone_him == 3)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? 0 : box->map_x,
				(box->odd % 2 == 0) ? e : f);
	if (box->zone_me == 1 && box->zone_him == 4)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? c : b,
				(box->odd % 2 == 0) ? 0 : box->map_y);
}

void	ft_zone_move_two(t_flr *box, int e, int f)
{
	int a;
	int b;
	int c;
	int d;

	a = box->map_x / 4;
	b = box->map_x / 2;
	c = (3 * box->map_x) / 4;
	d = box->map_y / 4;
	e = box->map_y / 2;
	f = (3 * box->map_y) / 4;
	if (box->zone_me == 2 && box->zone_him == 1)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? b : 0,
				(box->odd % 2 == 0) ? 0 : f);
	if (box->zone_me == 2 && box->zone_him == 2)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? a : 0,
				(box->odd % 2 == 0) ? 0 : f);
	if (box->zone_me == 2 && box->zone_him == 3)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? 0 : b,
				(box->odd % 2 == 0) ? e : box->map_y);
	if (box->zone_me == 2 && box->zone_him == 4)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? box->map_x : 0,
				(box->odd % 2 == 0) ? a : f);
}

void	ft_zone_move_three(t_flr *box, int e, int f)
{
	int a;
	int b;
	int c;
	int d;

	a = box->map_x / 4;
	b = box->map_x / 2;
	c = (3 * box->map_x) / 4;
	d = box->map_y / 4;
	e = box->map_y / 2;
	f = (3 * box->map_y) / 4;
	if (box->zone_me == 3 && box->zone_him == 1)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? 0 : c,
				(box->odd % 2 == 0) ? e : 0);
	if (box->zone_me == 3 && box->zone_him == 2)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? b : c,
				(box->odd % 2 == 0) ? 0 : box->map_y);
	if (box->zone_me == 3 && box->zone_him == 3)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? 0 : c,
				(box->odd % 2 == 0) ? e : box->map_y);
	if (box->zone_me == 3 && box->zone_him == 4)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? b : box->map_x,
				(box->odd % 2 == 0) ? box->map_y : d);
}

void	ft_zone_move_four(t_flr *box, int e, int f)
{
	int a;
	int b;
	int c;
	int d;

	a = box->map_x / 4;
	b = box->map_x / 2;
	c = (3 * box->map_x) / 4;
	d = box->map_y / 4;
	e = box->map_y / 2;
	f = (3 * box->map_y) / 4;
	if (box->zone_me == 4 && box->zone_him == 1)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? b : 0,
				(box->odd % 2 == 0) ? 0 : f);
	if (box->zone_me == 4 && box->zone_him == 2)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? 0 : box->map_x,
				(box->odd % 2 == 0) ? 0 : e);
	if (box->zone_me == 4 && box->zone_him == 3)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? a : b,
				(box->odd % 2 == 0) ? 0 : box->map_y);
	if (box->zone_me == 4 && box->zone_him == 4)
		ft_zm_attrib(box, (box->odd % 2 == 0) ? box->map_x : a,
				(box->odd % 2 == 0) ? e : box->map_y);
}

void	ft_zone_move(t_flr *box)
{
	if (box->zone_me == 1)
		ft_zone_move_one(box, 0, 0);
	else if (box->zone_me == 2)
		ft_zone_move_two(box, 0, 0);
	else if (box->zone_me == 3)
		ft_zone_move_three(box, 0, 0);
	else if (box->zone_me == 4)
		ft_zone_move_four(box, 0, 0);
}
