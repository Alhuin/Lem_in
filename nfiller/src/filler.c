/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nbettach <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 14:01:11 by nbettach     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 19:05:26 by nbettach    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
 * -------------------------------------------------------
 *
 * PIECE ET MAP DOIVENT ETRE TERMINEES PAR 0
 *
 * GO vers le centre, puis la pince, avec un padding de 10% de la max_dim de la
 * map, 5% pour des petites map. Si le padding est depasse on continu la pince
 * avec ce padding la.
 * Mais si le mec arrive au milieu de la pince ? Normalement, contact avec
 * padding de 0, engagement de l'algo de contact, a l'interieur de la pince...
 * A voir.
 * Apres avoir atteint le centre, il faut absolument fermer une partie de la map
 * recuperer la distance nous separant du bord le plus proche. Si de ce point
 * l'adversaire est a [2;4] cases de plus que nous en sommes du bord, on va vers
 * ce bord pour le fermer. Ne passe pas outre le contournement a padding 0.
 *
 * Calculer l'espace potentiel ?
 *
 * Si Depart passif :
 * Go centre, puis les bords, puis pince.
 * Sinon :
 * Go vers le gars, et le fucker.
 * Cas de contact : Chercher a :
 * Avoir le plus... ou le moins, de contact possible avec l'adversaire, tout en maximisant aussi
 * le contact avec les zones vides... plus ou moins ^^
 * Pour chaque coordonnees contenant une case remplie, on verifie si la piece
 * est posable, on conserve ses coordonnees si c'est le "meilleur" contact &&
 * offrant ensuite les "meilleures" possibilites ensuite.
 * Rejoindre un bord, c'est cool aussi.
 *
 * -------------------------------------------------------
*/

int	main(void)
{
	t_flr	*box;
	int		stop;

	stop = 0;
	box = NULL;
	while (101)
	{
		box = init_box(box, stop);
		stop = 1;
		//dprintf(2, "x : %i y : %i\n", box->map_x, box->map_y);
		if (ft_putable(box) == 101)
		{
			box = freeing_box(box, 1);
			ft_printf("0 0\n");
			exit(1);
		}
		else
		{
			if (box->dodo > 0 || ft_algo2(box))
				ft_put_piece(box, -1, -1, 0);
		}
		box = freeing_box(box, 0);
	}
	return (0);
}
