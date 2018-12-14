/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 23:17:23 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/14 16:35:10 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strncat(char *dest, char const *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (j < nb && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	j = ft_strlen(src);
	i = ft_strlen((char const *)dest);
	if (size <= i)
		return (j + size);
	if (size > i)
		ft_strncat(dest, src, size - i - 1);
	return (i + j);
}
