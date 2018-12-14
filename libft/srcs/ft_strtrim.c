/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:50:43 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/14 14:51:59 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_core(unsigned int i, unsigned int j, char *new, const char *s)
{
	unsigned int k;

	if (!(new = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	k = 0;
	while (k < i)
		new[k++] = s[j++];
	new[k] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	while (i && (s[i - 1] == '\t' || s[i - 1] == ' ' || s[i - 1] == '\n'))
		i--;
	j = 0;
	while (i && (s[j] == '\t' || s[j] == ' ' || s[j] == '\n'))
	{
		j++;
		i--;
	}
	new = NULL;
	new = ft_core(i, j, new, s);
	return (new);
}
