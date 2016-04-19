/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_till_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:37:21 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/31 20:35:27 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup_till_c(char *str, char c)
{
	static char	tmp[50];
	char		*cpy;
	int			i;

	i = 0;
	cpy = tmp;
	while (str[i] && str[i] != c)
	{
		tmp[i] = str[i];
		i++;
	}
	while (tmp[i])
	{
		tmp[i] = '\0';
		i++;
	}
	return (cpy);
}
