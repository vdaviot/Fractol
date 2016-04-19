/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 17:31:43 by vdaviot           #+#    #+#             */
/*   Updated: 2015/08/13 17:31:48 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		activate_orbit(t_frac *frac)
{
	if (frac->orbit == 0)
		frac->orbit = 1;
	else
		frac->orbit = 0;
	draw(frac);
}

void		activate_smooth(t_frac *frac)
{
	if (frac->smooth == 0)
		frac->smooth = 1;
	else
		frac->smooth = 0;
	draw(frac);
}
