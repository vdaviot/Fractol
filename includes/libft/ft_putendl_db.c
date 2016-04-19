/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 17:58:16 by vdaviot           #+#    #+#             */
/*   Updated: 2015/04/02 17:58:29 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_db(char *target, char *result)
{
	if (!target || !result)
		return ;
	ft_putstr(target);
	ft_putstr(" = ");
	ft_putendl(result);
}
