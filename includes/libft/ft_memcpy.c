/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:29:03 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/04 13:56:42 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*dest1;
	char	*src1;

	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
