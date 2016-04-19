/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 16:12:44 by vdaviot           #+#    #+#             */
/*   Updated: 2015/07/15 16:12:45 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cplx		cplx(double r, double i)
{
	t_cplx	c;

	c.r = r;
	c.i = i;
	return (c);
}

t_cplx		cplx_add(t_cplx vect, t_cplx vect1)
{
	t_cplx	v;

	v.r = vect.r + vect1.r;
	v.i = vect.i + vect1.i;
	return (v);
}

t_cplx		cplx_mult(t_cplx a, t_cplx b)
{
	t_cplx	c;

	c.r = a.r * b.r - a.i * b.i;
	c.i = a.r * b.i + a.i * b.r;
	return (c);
}
