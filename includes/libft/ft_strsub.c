/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:12:51 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/10 17:12:53 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	if (!s || !(str = ft_strnew(len)))
		return (NULL);
	while (k < len)
	{
		while (i < start)
			i++;
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
