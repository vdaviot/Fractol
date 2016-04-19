/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:09:59 by vdaviot           #+#    #+#             */
/*   Updated: 2015/02/17 16:44:14 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	k = i + j;
	if (size >= i)
	{
		while (i < (size - 1))
		{
			dst[i] = src[l];
			i++;
			l++;
		}
		dst[i] = '\0';
		return (k);
	}
	return (size + j);
}
