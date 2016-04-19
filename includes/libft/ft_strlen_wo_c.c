/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_wo_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 21:35:52 by vdaviot           #+#    #+#             */
/*   Updated: 2015/04/13 21:35:54 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_wo_c(char *str, char c, char d)
{
	int		j;
	int		i;
	int		k;

	i = 0;
	j = 0;
	k = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == c || str[i] == d)
			j++;
		i++;
	}
	k = k - j;
	return (k);
}
