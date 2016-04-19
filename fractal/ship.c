/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <vdaviot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 01:12:21 by vdaviot           #+#    #+#             */
/*   Updated: 2016/02/20 18:32:02 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				set_ship(t_frac *frac)
{
	frac->zoom = 100;
	frac->type.ship = 1;
	if (frac->max_iter != 0)
		;
	else
		frac->max_iter = 50;
	frac->movex = 0;
	frac->movey = 0;
}

static	int			do_iteration(t_frac *frac, int x, int y)
{
	register int	i;
	t_cplx			z;
	t_cplx			a;
	t_cplx			c;

	c.r = frac->x + ((x - (WINDOW_W / 2)) / frac->zoom);
	c.i = frac->y + ((y - (WINDOW_H / 2)) / frac->zoom);
	z = cplx(0.0, 0.0);
	a = cplx(c.r, c.i);
	i = -1;
	while (++i < frac->max_iter && z.r * z.r + z.i * z.i < 4.0)
	{
		z = cplx(fabs(z.r), fabs(z.i));
		z = cplx_add(cplx_mult(z, z), c);
	}
	orbit_trap_cplx(z, frac, i);
	return (i);
}

static void			buff_image_ship(t_img *img, t_frac *frac)
{
	register int	i;

	(void)img;
	frac->ty = 0;
	while (frac->ty < WINDOW_H)
	{
		frac->tx = 0;
		while (frac->tx < WINDOW_W)
		{
			frac->x = (long double)(1.5 * (frac->tx - (WINDOW_W / 2.0)) /
			(frac->zoom * WINDOW_W) + frac->movex);
			frac->y = (long double)((frac->ty - WINDOW_H / 2.0) /
			(frac->zoom * WINDOW_H) + frac->movey);
			i = do_iteration(frac, frac->tx, frac->ty);
			frac->tx++;
		}
		frac->ty++;
	}
}

void				draw_ship(t_img *img, t_frac *frac)
{
	buff_image_ship(img, frac);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
