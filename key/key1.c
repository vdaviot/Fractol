/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:53:56 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/30 14:53:59 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	switch_color(t_frac *frac)
{
	if (frac->colorise == 1)
		frac->colorise = 0;
	else
		frac->colorise = 1;
}

static	void	key_press(int keycode, t_frac *frac)
{
	if (keycode == R)
		reroll_color(frac);
	if (keycode == Q)
		blackandwhite(frac);
	if (keycode == W)
		activate_orbit(frac);
	if (keycode == E)
		activate_smooth(frac);
}

int				ft_key_press(int keycode, t_frac *frac)
{
	if (keycode == E || keycode == Q || keycode == W || keycode == R)
		key_press(keycode, frac);
	if (keycode == SPACE)
		switch_color(frac);
	if (keycode == PLUS)
		it_pp(frac);
	if (keycode == MOIN)
		it_mm(frac);
	if (keycode == ESC)
		exit(0);
	if (keycode == FORWARD)
		forward(frac);
	if (keycode == BACKWARD)
		backward(frac);
	if (keycode == LEFT)
		left(frac);
	if (keycode == RIGHT)
		right(frac);
	draw_tt(&frac->img, frac);
	return (0);
}

int				ft_move_mouse(int x, int y, t_frac *frac)
{
	long double	mid_x;
	long double	mid_y;

	mid_x = WINDOW_W / 2;
	mid_y = WINDOW_H / 2;
	frac->c_real = (long double)(1 - (long double)(x / mid_x));
	frac->c_imag = (long double)(1 - (long double)(y / mid_y));
	draw(frac);
	return (0);
}

int				ft_mouse_hook(int button, int x, int y, t_frac *frac)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom(frac);
	if (button == 5)
		dezoom(frac);
	draw(frac);
	return (0);
}
