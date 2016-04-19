/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:50:50 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/03 14:50:53 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	cpy = ft_strnew(i + 1);
	i = -1;
	while (cpy && s1 && s1[++i])
		cpy[i] = s1[i];
	return (cpy);
}
