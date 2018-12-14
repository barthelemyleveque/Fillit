/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:45:29 by thzimmer          #+#    #+#             */
/*   Updated: 2018/12/09 14:25:33 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*psrc;
	unsigned char	*pdest;
	unsigned char	ch;

	ch = (unsigned char)c;
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdest[0] = psrc[i];
		pdest++;
		if (psrc[i] == ch)
			return (pdest);
		i++;
	}
	return (NULL);
}
