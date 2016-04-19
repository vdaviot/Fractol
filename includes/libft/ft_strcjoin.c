/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 20:24:38 by vdaviot           #+#    #+#             */
/*   Updated: 2015/04/01 20:24:42 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char *s1, char *s2, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i++] = c;
	while (s2[j])
	{
		tmp[i] = s2[j];
		j++;
		i++;
	}
	return (tmp);
}
