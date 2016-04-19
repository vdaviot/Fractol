/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <vdaviot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:21:25 by vdaviot           #+#    #+#             */
/*   Updated: 2016/02/25 17:44:20 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void						set_julia(t_frac *frac)
{
	frac->orbit = 0;
	frac->smooth = 0;
	frac->type.julia = 1;
	frac->zoom = 1;
	frac->zoomx = 0;
	frac->zoomy = 0;
	if (frac->max_iter)
		;
	else
		frac->max_iter = 42;
	frac->movex = 0;
	frac->movey = 0;
	frac->c_real = -0.7;
	frac->c_imag = 0.27015;
}

inline static	t_coord		do_iteration(t_frac *frac, double x, double y)
{
	register int			i;
	t_frac					sec;
	t_coord					c;
	register	double		old_real;
	register	double		old_imag;

	i = 0;
	sec.x = x;
	sec.y = y;
	while (i < frac->max_iter)
	{
		if ((sec.x * sec.x + sec.y * sec.y) > 4.0)
			break ;
		old_real = sec.x;
		old_imag = sec.y;
		sec.y = (2.0 * old_real * old_imag) + frac->c_imag;
		sec.x = old_real * old_real - old_imag * old_imag + frac->c_real;
		i++;
	}
	c.x = sec.x;
	c.y = sec.y;
	c.i = i;
	return (c);
}

inline	void				colorise(t_frac *frac, double color, t_coord c)
{
	if (frac->colorise == 1)
	{
		if (c.i != frac->max_iter)
			mlx_pixel_put_to_image(&frac->img, c.x, c.y, (int)color % 2);
		else
			mlx_pixel_put_to_image(&frac->img, c.x, c.y, color);
	}
	else
	{
		if (c.i != frac->max_iter)
			mlx_pixel_put_to_image(&frac->img, c.x, c.y, color);
		else
			mlx_pixel_put_to_image(&frac->img, c.x, c.y, (int)color % 2);
	}
}

void						*buff_img_julia(int start, int end, t_frac *frac)
{
	t_coord					i;
	t_point					t;
	register double			x;
	register double			y;
	register double			color;

	while (start < end)
	{
		t.y = start;
		t.x = 0;
		while (t.x < WINDOW_W)
		{
			x = (double)(1.5 * (t.x - (WINDOW_W / 2.0)) /
				(0.5 * frac->zoom * WINDOW_W) + frac->movex);
			y = (double)((t.y - WINDOW_H / 2.0) /
				(0.5 * frac->zoom * WINDOW_H) + frac->movey);
			i = do_iteration(frac, x, y);
			color = select_coloration(i, frac);
			i.x = t.x++;
			i.y = t.y;
			colorise(frac, color, i);
		}
		start++;
	}
	return (NULL);
}

void						draw_julia(t_img *img, t_frac *frac)
{
	init_thread(frac);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	print_str_to_window(frac);
}
