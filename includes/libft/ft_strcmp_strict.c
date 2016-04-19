/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_strict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:35:03 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/31 20:35:06 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_strict(char *s1, char *s2)
{
	int		i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (-1);
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
