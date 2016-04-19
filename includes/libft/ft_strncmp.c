/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:16:49 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/08 12:29:37 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*str1;
	char		*str2;

	i = 0;
	str1 = (char*)s1;
	str2 = (char*)s2;
	if (!n)
		return (0);
	while (str1 && str2 && i < n)
	{
		if (!(*str1 || *str2) || *str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	return (0);
}
