/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 15:36:06 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/02 15:36:07 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	t_coord			do_iteration(t_frac *frac, double x, double y)
{
	register	int		i;
	t_coord				c;
	t_frac				sec;
	long double			tmp;

	i = 0;
	sec.x = 0;
	sec.y = 0;
	c.x = x;
	c.y = y;
	while (i < frac->max_iter && (sec.x * sec.x + sec.y * sec.y) < 4.0)
	{
		tmp = sec.x;
		sec.x = sec.x * sec.x - sec.y * sec.y + c.x;
		sec.y = (2.0 * tmp * sec.y) - c.y;
		i++;
	}
	c.x = sec.x * sec.x;
	c.y = sec.y * sec.y;
	c.i = i;
	return (c);
}

void					buff_img_mandel(int start, int end, t_frac *frac)
{
	t_coord				i;
	t_point				t;
	register double		x;
	register double		y;
	register double		color;

	while (start < end)
	{
		y = start;
		x = 0;
		while (x < WINDOW_W)
		{
			t.x = (double)((x - (WINDOW_W / 2.0)) /
				frac->zoom) + frac->movex;
			t.y = (double)((y - (WINDOW_H / 2.0)) /
				frac->zoom) + frac->movey;
			i = do_iteration(frac, t.x, t.y);
			color = select_coloration(i, frac);
			i.x = x;
			i.y = y;
			colorise(frac, color, i);
			x++;
		}
		start++;
	}
}

void					set_mandel(t_frac *frac)
{
	frac->type.mandel = 1;
	frac->zoom = 150.0;
	if (frac->max_iter != 0)
		;
	else
		frac->max_iter = 100;
	frac->movex = 1;
	frac->movey = 1;
}

void					draw_mandelbrot(t_img *img, t_frac *frac)
{
	init_thread(frac);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	print_str_to_window(frac);
}
