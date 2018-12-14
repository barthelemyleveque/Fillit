/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:52:30 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/08 17:58:22 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	if (c == '\0')
		return ((char *)s + len);
	while (s[len] != c && len >= 0)
		len--;
	if (len == -1)
		return (NULL);
	return ((char *)s + len);
}
