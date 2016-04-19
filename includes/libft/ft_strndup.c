/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:35:49 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/31 20:35:53 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*cpy;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	cpy = ft_strnew(i);
	i = 0;
	while (cpy && s1 && s1[n])
	{
		cpy[i] = s1[n];
		i++;
		n++;
	}
	cpy[i] = '\0';
	return (cpy);
}
