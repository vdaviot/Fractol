/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenv_addend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:34:48 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/09 20:34:50 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lenv		*ft_lenv_addend(t_lenv *env, void *data)
{
	t_lenv	*tmp;
	t_lenv	*plist;

	plist = ft_lenv_create(data);
	if (!env)
		return (plist);
	else
	{
		tmp = env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = plist;
		plist->next = NULL;
	}
	return (env);
}
