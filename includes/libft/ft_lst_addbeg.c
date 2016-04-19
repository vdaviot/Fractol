/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addbeg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:37:21 by vdaviot           #+#    #+#             */
/*   Updated: 2014/12/05 17:37:25 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_addbeg(t_list *old, void *data)
{
	t_list	*list;

	list = ft_lst_create(data);
	if (list)
		list->next = old;
	return (list);
}
