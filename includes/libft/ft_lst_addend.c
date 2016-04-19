/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:37:08 by vdaviot           #+#    #+#             */
/*   Updated: 2014/12/05 17:37:10 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_addend(t_list *list, void *data)
{
	t_list	*tmp;
	t_list	*plist;

	plist = ft_lst_create(data);
	if (!list)
		return (plist);
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = plist;
	}
	return (list);
}
