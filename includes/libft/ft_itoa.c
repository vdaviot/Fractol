/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:22:36 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/15 15:22:38 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	size_t			lenght;
	char			*s;
	unsigned int	nbr;

	lenght = ft_count_digits(n);
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		lenght++;
	}
	if ((s = malloc(sizeof(char) * lenght)) == NULL)
		return (NULL);
	s[lenght] = '\0';
	s[--lenght] = nbr % 10 + '0';
	while (nbr /= 10)
		s[--lenght] = nbr % 10 + '0';
	if (n < 0)
		s[0] = '-';
	return (s);
}
