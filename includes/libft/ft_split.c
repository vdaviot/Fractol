/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 18:11:03 by vdaviot           #+#    #+#             */
/*   Updated: 2015/04/01 18:11:04 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	k = 0;
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == c)
			j++;
	while (str[i] != c)
		i--;
	tmp = ft_strnew(i + 1);
	i = -1;
	while (str[++i] && j > 0)
	{
		if (str[i] == c)
			j--;
		tmp[k] = str[i];
		k++;
	}
	tmp[i - 1] = '\0';
	return (tmp);
}
