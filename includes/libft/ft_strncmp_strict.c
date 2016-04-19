/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_strict.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:35:39 by vdaviot           #+#    #+#             */
/*   Updated: 2015/03/31 20:35:42 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp_strict(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	if (ft_strlen(s2) != ft_strlen(s1))
		return (-1);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
