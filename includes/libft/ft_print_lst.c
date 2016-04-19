/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:07:53 by vdaviot           #+#    #+#             */
/*   Updated: 2014/12/08 20:08:54 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_lst(t_list *list)
{
	while (list)
	{
		ft_putendl(list->data);
		ft_putstr(list->data);
		list = list->next;
	}
}
