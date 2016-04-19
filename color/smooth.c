/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 15:44:44 by vdaviot           #+#    #+#             */
/*   Updated: 2015/08/05 15:44:48 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double		smooth(t_frac *frac, t_coord *sec, int i, long color)
{
	t_color			c;
	static int		count = 0;

	if (count == MAX_COLOR)
		count = 0;
	c.color_start = color;
	c.color_end = frac->color[i % MAX_COLOR + 1];
	c.dist = i - log(log(SQRT(sec->x) + SQRT(sec->y))) / log(2);
	count++;
	c.r_rat = ((((c.color_end >> 16) & 0xff) - ((c.color_start >> 16) & 0xff))
		* c.dist);
	c.g_rat = ((((c.color_end >> 8) & 0xff) - ((c.color_start >> 8) & 0xff))
		* c.dist);
	c.b_rat = ((((c.color_end) & 0xff) - ((c.color_start) & 0xff)) * c.dist);
	c.color_a = ((c.b_rat) + ((c.g_rat) << 8) + ((c.r_rat) << 16));
	return (c.color_a);
}
