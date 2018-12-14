/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:25:53 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/10 11:47:00 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		*data;
	size_t	i;

	i = 0;
	if (!(data = (int *)malloc(sizeof(int) * size + 1)))
		return (NULL);
	while (i < size)
		data[i++] = 0;
	return (data);
}
