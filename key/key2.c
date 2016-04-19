/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:54:07 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/30 14:54:08 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	left(t_frac *frac)
{
	frac->movex += 0.5 / frac->zoom;
	draw(frac);
}

void	right(t_frac *frac)
{
	frac->movex -= 0.5 / frac->zoom;
	draw(frac);
}

void	forward(t_frac *frac)
{
	frac->movey += 0.5 / frac->zoom;
	draw(frac);
}

void	backward(t_frac *frac)
{
	frac->movey -= 0.5 / frac->zoom;
	draw(frac);
}

void	reroll_color(t_frac *frac)
{
	color_table(frac);
	draw(frac);
}
