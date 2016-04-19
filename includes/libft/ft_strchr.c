/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:14:05 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/04 16:14:07 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	char		*temp;

	temp = (char *)s;
	while (*temp != c && *temp)
		temp++;
	if (*temp != c)
		return (NULL);
	return (temp);
}
