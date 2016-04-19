/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:23:10 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/11 16:23:11 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t		ft_count_words(char const *s, char c)
{
	size_t			i;

	i = 0;
	if (!c || !s)
		return (-1);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char			*ft_get_words(char *s, char c, char **tmp)
{
	size_t			i;
	char			*tempo;

	tempo = *tmp;
	s = NULL;
	while (*tempo && *tempo == c)
		tempo++;
	i = 0;
	while (tempo[i] && tempo[i] != c)
		i++;
	if (i)
	{
		s = ft_strnew(i);
		ft_strncpy(s, tempo, i);
		tempo = tempo + i;
	}
	*tmp = tempo;
	return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	size_t			i;
	int				j;
	char			*tmp;

	if (!s || !c)
		return (NULL);
	j = ft_count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	i = 0;
	tmp = ft_strdup(s);
	while (i < j)
	{
		tab[i] = ft_get_words((char *)s, c, &tmp);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
