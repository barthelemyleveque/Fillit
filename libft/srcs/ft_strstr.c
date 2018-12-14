/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 23:18:58 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/14 13:09:01 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strstr(char const *str, char const *to_find)
{
	int				i;
	int				j;
	unsigned char	*pstr;
	unsigned char	*pto_find;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	pstr = (unsigned char *)str;
	pto_find = (unsigned char *)to_find;
	while (pstr[i])
	{
		if (pstr[i] == pto_find[0])
		{
			j = 0;
			while (pstr[i + j] == pto_find[j])
			{
				if (pto_find[j + 1] == '\0')
					return ((char *)pstr + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
