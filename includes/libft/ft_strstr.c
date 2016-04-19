/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:19:33 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/04 14:19:37 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2)
		return ((char *)s1);
	while (s1[i])
	{
		while (s1[i] == s2[j] && s2[j])
		{
			j++;
			i++;
		}
		if (s2[j] == '\0')
			return ((char*)s1);
		else
		{
			j = 0;
			i = 0;
			s1++;
		}
	}
	return (NULL);
}
