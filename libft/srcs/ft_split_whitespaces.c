/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 01:53:48 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/11 14:45:57 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_word_count(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str > 32)
		{
			i++;
			while (*str > 32 && *str)
				str++;
		}
		if (*str == '\0')
			return (i);
		str++;
	}
	return (i);
}

static int	*ft_wordpos(char *str)
{
	int i;
	int j;
	int *arr;

	i = 0;
	j = 0;
	if (!(arr = (int*)malloc(sizeof(int) * (ft_word_count(str)))))
		return (NULL);
	while (str[i] <= 32 && str[i])
		i++;
	while (str[i])
	{
		if (str[i] > 32)
		{
			arr[j++] = i;
			i++;
			while (str[i] > 32 && str[i])
				i++;
		}
		i++;
	}
	return (arr);
}

static int	*ft_wordlen(char *str)
{
	int i;
	int j;
	int k;
	int *arr;

	i = 0;
	j = 0;
	k = 0;
	arr = (int*)malloc(sizeof(int) * (ft_word_count(str)));
	while (str[i])
	{
		while (str[i] <= 32 && str[i])
			i++;
		while (str[i] > 32 && str[i])
		{
			j++;
			if (str[i + 1] <= 32 && str[i])
			{
				arr[k++] = j;
				j = 0;
			}
			i++;
		}
	}
	return (arr);
}

static void	ft_norminette(int **arr1, int **arr2, char *str)
{
	*arr1 = ft_wordlen(str);
	*arr2 = ft_wordpos(str);
}

char		**ft_split_whitespaces(char *str)
{
	int		i;
	int		j;
	int		*wordlen;
	int		*wordpos;
	char	**tab;

	i = 0;
	ft_norminette(&wordlen, &wordpos, str);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_word_count(str) + 1))))
		return (NULL);
	while (i < ft_word_count(str))
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (wordlen[i] + 1))))
			return (NULL);
		while (j < wordlen[i])
		{
			tab[i][j] = str[wordpos[i] + j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
