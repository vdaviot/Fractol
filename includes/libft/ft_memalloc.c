/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:56:40 by vdaviot           #+#    #+#             */
/*   Updated: 2014/11/10 13:56:44 by vdaviot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (!size || !(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (--size)
		str[size] = '\0';
	return ((void*)str);
}
