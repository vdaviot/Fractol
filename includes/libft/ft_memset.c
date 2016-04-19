/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:33:36 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/03 16:05:37 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void		*ft_memset(void *s, int c, size_t n)
{
	char			*temp;
	unsigned int	i;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (s);
}
