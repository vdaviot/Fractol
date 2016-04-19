/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 15:23:44 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/09 15:23:46 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_lenv(t_lenv *lenv)
{
	while (lenv)
	{
		ft_putendl(lenv->data);
		if (lenv->next)
			lenv = lenv->next;
		else
			return ;
	}
}
