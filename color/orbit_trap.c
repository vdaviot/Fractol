/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orbit_trap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 20:18:47 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/30 16:24:27 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double			orbit_trap(t_coord *sec, t_frac *frac)
{
	register	double		r;
	register	double		color;

	r = sec->x * sec->x + sec->y * sec->y;
	r = log(r) / 4.0 / log(M_PI) - atan2(sec->x, sec->y) / 3.0 * M_PI;
	r = fabs(r - round(r));
	if (r > 2 || r < 0)
		r = 0.0;
	else
		r = 1.0 - (r / 2.0);
	color = frac->color[(int)(r * 20.0) % MAX_COLOR];
	return (color);
}

void			orbit_trap_cplx(t_cplx z, t_frac *frac, int i)
{
	register	double		r;

	r = z.r * z.r + z.i * z.i;
	r = log(r) / 4.0 / log(M_PI) - atan2(z.r, z.i) / 2.0 * M_PI;
	r = fabs(r - round(r));
	if (r > 2 || r < 0)
		r = 0.0;
	else
		r = 1.0 - (r / 2.0);
	if (i != frac->max_iter)
		mlx_pixel_put_to_image(&frac->img, frac->tx, frac->ty,
			frac->color[(int)(r * 18.0) % MAX_COLOR]);
	else
		mlx_pixel_put_to_image(&frac->img, frac->tx, frac->ty, 0);
}
