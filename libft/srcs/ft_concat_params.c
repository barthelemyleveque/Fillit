/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:51:39 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/10 14:33:45 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		z;
	char	*str;

	if (!argv)
		return (NULL);
	z = 0;
	j = 1;
	while (j < argc)
		z = z + ft_strlen(argv[j++]);
	if ((str = (char*)malloc(sizeof(int) * (z + argc - 1))) == NULL)
		return (NULL);
	j = 1;
	z = 0;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
			str[z++] = argv[j][i++];
		j++;
	}
	str[z] = '\0';
	return (str);
}
