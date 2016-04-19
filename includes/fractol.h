/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <vdaviot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/02 15:32:03 by vdaviot           #+#    #+#             */
/*   Updated: 2016/04/19 15:53:37 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <math.h>
# include <time.h>
# include <pthread.h>

# define R 15
# define E 14
# define W 13
# define Q 12
# define SPACE 49
# define WINDOW_W 800
# define WINDOW_H 600
# define FORWARD 126
# define BACKWARD 125
# define LEFT 123
# define RIGHT 124
# define PLUS 69
# define MOIN 78
# define ESC 53
# define RED 0xE83233
# define BLUE 0x5AE1FF
# define GREEN 0x69E868
# define YELLOW 0xE5C200
# define GREY 0xABA6B0
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define ORANGE 0xFF7E13
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6
# define SQRT(x) (x * x)
# define MAX_COLOR 10
# define THREAD_NUM 8

typedef	struct		s_color
{
	char			rgb[4];
	double			color;
	long double		dist;
	int				color_start;
	int				color_end;
	unsigned char	r_rat;
	unsigned char	g_rat;
	unsigned char	b_rat;
	double			color_a;
}					t_color;

typedef	struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef	struct		s_img
{
	void			*mlx;
	void			*win;
	void			*img;
	int				sline;
	int				bpp;
	int				endian;
	char			*data;
}					t_img;

typedef	struct		s_type
{
	int				mandel;
	int				julia;
	int				triangle;
	int				ship;
}					t_type;

typedef	struct		s_cplx
{
	double			r;
	double			i;
}					t_cplx;

typedef	struct		s_coord
{
	double			x;
	double			y;
	double			ty;
	double			tx;
	int				i;
}					t_coord;

typedef	struct		s_frac
{
	long double		zoom;
	long double		zoomy;
	long double		zoomx;
	int				max_iter;
	double			img_x;
	double			img_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			x;
	double			y;
	double			c_real;
	double			c_imag;
	char			*av;
	double			movex;
	double			movey;
	int				color[MAX_COLOR];
	t_img			img;
	t_color			*col;
	t_type			type;
	t_cplx			*cplx;
	long double		ty;
	long double		tx;
	int				orbit;
	int				smooth;
	int				colorise;
}					t_frac;

typedef	struct		s_thread
{
	int				start;
	int				end;
	t_frac			*struc;
}					t_thread;

typedef struct		s_tra
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	char			ran;
}					t_tra;

void				buff_img_triangle(t_img *img, t_frac *frac);
int					ft_move_mouse(int x, int y, t_frac *frac);
void				mlx_pixel_put_to_image(t_img *img, int x, int y, int color);
void				mandelbrot(t_img *img, t_frac frac);
int					ft_key_press(int keycode, t_frac *frac);
int					ft_mouse_hook(int button, int x, int y, t_frac *frac);
void				draw_mandelbrot(t_img *img, t_frac *frac);
int					expose(t_img *img);
void				set_mandel(t_frac *frac);
void				get_color(int r, int g, int b, t_color *color);
void				draw_julia(t_img *img, t_frac *frac);
void				set_julia(t_frac *frac);
void				draw_breach(t_img *img, t_frac *frac);
int					hsl_to_hex(int h, float s, float l);
t_cplx				cplx_mult(t_cplx a, t_cplx b);
t_cplx				cplx_add(t_cplx vect, t_cplx vect1);
t_cplx				cplx(double r, double i);
void				set_ship(t_frac *frac);
void				draw_ship(t_img *img, t_frac *frac);
void				draw_sierpinski(t_img *img, t_frac *frac);
void				set_triangle(t_frac *frac);
void				color_table(t_frac *frac);
unsigned long		hex_to_rgb(int r, int g, int b);
void				orbit_trap_cplx(t_cplx z, t_frac *frac, int i);
void				check_arg(char **av, t_img *img, t_frac *frac);
double				smooth(t_frac *frac, t_coord *sec, int i, long color);
void				*buff_img_julia(int s, int e, t_frac *frac);
pthread_t			add_thread(int s, int e, void *struc, int i);
void				init_thread(void *struc);
void				print_str_to_window(t_frac *frac);
void				left(t_frac *frac);
void				right(t_frac *frac);
void				forward(t_frac *frac);
void				backward(t_frac *frac);
void				reroll_color(t_frac *frac);
void				zoom(t_frac *frac);
void				dezoom(t_frac *frac);
void				it_pp(t_frac *frac);
void				it_mm(t_frac *frac);
void				draw(t_frac *frac);
void				buff_img_mandel(int	start, int end, t_frac *frac);
void				blackandwhite(t_frac *frac);
void				activate_orbit(t_frac *frac);
void				activate_smooth(t_frac *frac);
double				select_coloration(t_coord c, t_frac *frac);
void				simple_color(t_frac *sec, t_frac *frac, int i);
void				draw_tt(t_img *img, t_frac *frac);
double				orbit_trap(t_coord *sec, t_frac *frac);
void				colorise(t_frac *frac, double color, t_coord c);

#endif
