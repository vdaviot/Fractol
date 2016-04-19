/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 16:24:36 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/02 16:24:39 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			mlx_pixel_put_to_image(t_img *img, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WINDOW_W * WINDOW_H * img->bpp / 8;
	if (x < 0 || y < 0 || y * img->sline + x * img->bpp / 8 > img_size
		|| x >= img->sline / (img->bpp / 8) || y >= img_size / img->sline)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = img->bpp / 8;
	img->data[y * img->sline + x * bit_pix] = color1;
	img->data[y * img->sline + x * bit_pix + 1] = color2;
	img->data[y * img->sline + x * bit_pix + 2] = color3;
}
