/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:09:52 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/04 17:09:55 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s) + 1;
	while (i > 0 && s[i - 1] != c)
		i--;
	if (i > 0)
		return ((char *)s + i - 1);
	else
		return (NULL);
}
