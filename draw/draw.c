/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 15:10:46 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/30 15:10:48 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_str_to_window(t_frac *frac)
{
	char	*iter;
	char	*zoom;

	iter = ft_itoa(frac->max_iter);
	zoom = ft_itoa(frac->zoom);
	mlx_string_put(frac->img.mlx, frac->img.win, 10, 20, WHITE,
		"Iterations : ");
	mlx_string_put(frac->img.mlx, frac->img.win, 140, 20, WHITE,
		iter);
	mlx_string_put(frac->img.mlx, frac->img.win, 10, 40, WHITE,
		"Zoom : ");
	mlx_string_put(frac->img.mlx, frac->img.win, 80, 40, WHITE,
		zoom);
	free(iter);
	free(zoom);
}

void	draw_tt(t_img *img, t_frac *frac)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	print_str_to_window(frac);
}

void	draw(t_frac *frac)
{
	if (frac->type.mandel == 1)
		draw_mandelbrot(&frac->img, frac);
	if (frac->type.julia == 1)
		draw_julia(&frac->img, frac);
	if (frac->type.ship == 1)
		draw_ship(&frac->img, frac);
	if (frac->type.triangle == 1)
		draw_sierpinski(&frac->img, frac);
	print_str_to_window(frac);
}

void	draw_sierpinski(t_img *img, t_frac *frac)
{
	buff_img_triangle(img, frac);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
