/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenv_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:34:57 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/09 20:35:00 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lenv	*ft_lenv_create(void *data)
{
	t_lenv	*env;

	if (!(env = (t_lenv *)malloc(sizeof(t_lenv))))
		return (NULL);
	else if (env)
	{
		env->data = data;
		env->next = NULL;
	}
	return (env);
}
