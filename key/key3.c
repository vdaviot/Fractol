/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 14:54:14 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/30 14:54:15 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_frac *frac)
{
	frac->zoom *= 1.1;
	draw(frac);
}

void	dezoom(t_frac *frac)
{
	frac->zoom /= 1.1;
	draw(frac);
}

void	it_pp(t_frac *frac)
{
	frac->max_iter += 1;
	draw(frac);
}

void	it_mm(t_frac *frac)
{
	frac->max_iter -= 1;
	draw(frac);
}
