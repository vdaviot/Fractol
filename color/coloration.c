/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloration.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 20:04:18 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/30 20:04:19 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned long				hex_to_rgb(int r, int g, int b)
{
	return ((r & 0xff) + ((g & 0xff) << 8) + ((b & 0xff) << 16));
}

int							hsl_to_hex(int h, float s, float l)
{
	t_color					color;
	register long double	c;
	register long double	x;
	register long double	m;

	c = (1.0 - fabs(2 * l - 1.0)) * s;
	x = c * (1.0 - fabs(fmod((h / 60.0), 2.0) - 1.0));
	m = l - 0.5 * c;
	if (h >= 0 && h < 60)
		color.color = hex_to_rgb((c + m) * 255, (x + m) * 255, (0 + m) * 255);
	else if (h >= 60 && h < 120)
		color.color = hex_to_rgb((x + m) * 255, (c + m) * 255, (0 + m) * 255);
	else if (h >= 120 && h < 180)
		color.color = hex_to_rgb((0 + m) * 255, (c + m) * 255, (x + m) * 255);
	else if (h >= 180 && h < 240)
		color.color = hex_to_rgb((0 + m) * 255, (x + m) * 255, (c + m) * 255);
	else if (h >= 240 && h < 300)
		color.color = hex_to_rgb((x + m) * 255, (0 + m) * 255, (c + m) * 255);
	else if (h >= 300 && h < 360)
		color.color = hex_to_rgb((c + m) * 255, (0 + m) * 255, (x + m) * 255);
	else
		color.color = hex_to_rgb(255, 255, 255);
	return (color.color);
}

inline	double				select_coloration(t_coord c, t_frac *frac)
{
	register double			color;

	if (frac->smooth == 0 && frac->orbit == 0)
		color = frac->color[c.i % MAX_COLOR];
	if (frac->orbit == 1 && frac->smooth == 1)
		color = smooth(frac, &c, c.i, orbit_trap(&c, frac));
	if (frac->smooth == 1 && frac->orbit == 0)
		color = smooth(frac, &c, c.i, frac->color[c.i % MAX_COLOR]);
	if (frac->orbit == 1 && frac->smooth == 0)
		color = orbit_trap(&c, frac);
	return (color);
}

void						color_table(t_frac *frac)
{
	register int			i;
	register int			r;
	register int			g;
	register int			b;

	i = -1;
	r = 25;
	g = 100;
	b = 255;
	srand(time(NULL) + clock());
	while (++i < MAX_COLOR)
		frac->color[i] = hex_to_rgb(rand() % r, rand() % g, rand() % b);
}

void						blackandwhite(t_frac *frac)
{
	register int	i;

	i = -1;
	while (++i < MAX_COLOR)
	{
		if (i % 2)
			frac->color[i] = WHITE;
		else
			frac->color[i] = BLACK;
	}
	draw(frac);
}
