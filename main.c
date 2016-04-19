/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 15:27:52 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/02 15:27:53 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

static	void		set_mlx(char *av, t_img *img)
{
	if (!(img->mlx = mlx_init()))
		return ;
	img->win = mlx_new_window(img->mlx, WINDOW_W, WINDOW_H, av);
	img->img = mlx_new_image(img->mlx, WINDOW_W, WINDOW_H);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sline,
	&img->endian);
}

static	void		init_color(t_frac *frac, char **av)
{
	color_table(frac);
	set_mlx(av[1], &frac->img);
	frac->type.julia = 0;
	frac->type.mandel = 0;
	frac->type.ship = 0;
	frac->type.triangle = 0;
	frac->colorise = 0;
}

void				check_arg(char **av, t_img *img, t_frac *frac)
{
	if (av[2])
		frac->max_iter = ft_atoi(av[2]);
	init_color(frac, av);
	if (ft_strequ(av[1], "mandel") == 1)
	{
		set_mandel(frac);
		draw_mandelbrot(img, frac);
	}
	else if (ft_strequ(av[1], "julia") == 1)
	{
		set_julia(frac);
		draw_julia(img, frac);
	}
	else if (ft_strequ(av[1], "ship") == 1)
	{
		set_ship(frac);
		draw_ship(img, frac);
	}
	else if (ft_strequ(av[1], "triangle") == 1)
	{
		set_triangle(frac);
		draw_sierpinski(img, frac);
	}
	else
		exit(0);
}

void				cat_readme(void)
{
	char	buff[0xf00];
	int		fd;

	fd = open("README", O_RDONLY);
	while (read(fd, buff, 1) != 0)
		write(1, buff, 1);
	close(fd);
}

int					main(int ac, char **av)
{
	t_frac			frac;

	if (ac >= 2)
		check_arg(av, &frac.img, &frac);
	else
	{
		cat_readme();
		return (0);
	}
	mlx_mouse_hook(frac.img.win, ft_mouse_hook, &frac);
	mlx_hook(frac.img.win, 2, 1, ft_key_press, &frac);
	mlx_hook(frac.img.win, MOTIONNOTIFY, POINTERMOTIONMASK, ft_move_mouse,
		&frac);
	mlx_loop(frac.img.mlx);
}
