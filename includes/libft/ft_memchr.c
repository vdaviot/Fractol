/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:29:57 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/06 18:29:59 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*tp;

	if (!s)
		return (NULL);
	tp = (char*)s;
	i = 0;
	while (i < n)
	{
		if (*tp == (unsigned char)c)
			return (tp);
		tp++;
		i++;
	}
	return (NULL);
}
