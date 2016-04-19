/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <vdaviot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 16:17:05 by vdaviot           #+#    #+#             */
/*   Updated: 2016/02/20 17:09:40 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void					*lthread(void *th)
{
	t_thread			*t;

	t = th;
	if (t->struc->type.julia == 1)
		buff_img_julia(t->start, t->end, t->struc);
	if (t->struc->type.mandel == 1)
		buff_img_mandel(t->start, t->end, t->struc);
	return (NULL);
}

pthread_t				add_thread(int s, int e, void *struc, int i)
{
	static t_thread		thread[THREAD_NUM];
	pthread_t			rax;

	thread[i].start = s - 1;
	thread[i].end = e;
	thread[i].struc = struc;
	if (pthread_create(&rax, NULL, (void *(*)(void *))lthread, &thread[i]))
		exit(0);
	return (rax);
}

void					init_thread(void *stru)
{
	register int		i;
	int					j;
	pthread_t			pid[THREAD_NUM];
	t_thread			thread[THREAD_NUM];
	t_frac				*struc;

	i = -1;
	j = (WINDOW_H / THREAD_NUM);
	struc = stru;
	while (++i < THREAD_NUM)
	{
		thread[i].start = j * i;
		thread[i].end = j * (i + 1);
		thread[i].struc = struc;
		if (pthread_create(&pid[i], NULL, lthread, &thread[i]))
			exit(0);
	}
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(pid[i], NULL);
}
