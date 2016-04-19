/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triforce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 16:34:20 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/20 16:34:21 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				set_triangle(t_frac *frac)
{
	frac->type.triangle = 1;
	frac->max_iter = 10000000;
}

static	void		triangle_one(t_tra *tra)
{
	tra->x1 = (tra->x2 + 320) / 2;
	tra->y1 = (tra->y2 + 0) / 2;
}

static	void		triangle_two(t_tra *tra)
{
	tra->x1 = (tra->x2 + 0) / 2;
	tra->y1 = (tra->y2 + 480) / 2;
}

static	void		triangle_three(t_tra *tra)
{
	tra->x1 = (tra->x2 + 640) / 2;
	tra->y1 = (tra->y2 + 480) / 2;
}

void				buff_img_triangle(t_img *img, t_frac *frac)
{
	register int	i;
	t_tra			tra;

	tra.x1 = 320;
	tra.x2 = 320;
	tra.y1 = 0;
	tra.y2 = 0;
	i = 0;
	while (i < frac->max_iter)
	{
		if ((tra.ran = random()) > 2)
			tra.ran = random();
		if (tra.ran == 0)
			triangle_one(&tra);
		else if (tra.ran == 1)
			triangle_two(&tra);
		else if (tra.ran == 2)
			triangle_three(&tra);
		mlx_pixel_put_to_image(img, tra.x1, tra.y1, frac->color[i % MAX_COLOR]);
		i++;
		tra.x2 = tra.x1;
		tra.y2 = tra.y1;
	}
}
