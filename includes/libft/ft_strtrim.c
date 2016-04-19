/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:25:11 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/11 14:25:12 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s || !(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s)
	{
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j++;
		if (!s[j])
			break ;
		tmp[++i] = *s++;
		j = 0;
	}
	tmp[++i] = '\0';
	return (tmp);
}
