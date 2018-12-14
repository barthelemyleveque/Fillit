/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:20:42 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/10 18:10:30 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static long int	ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	return (n * ft_pow(n, p - 1));
}

static char		*ft_calc(int n)
{
	int		i;
	char	*result;

	i = 0;
	if (n < 0)
		n *= -1;
	while (ft_pow(2, i) - 1 < n)
		i++;
	if (!(result = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	result[i] = '\0';
	while (i-- > 0)
	{
		result[i] = n % 2 + '0';
		n = n / 2;
	}
	return (result);
}

static char		*ft_getdots(int n)
{
	int		i;
	int		j;
	char	*calc;
	char	*result;

	if (!(calc = ft_calc(n)))
		return (NULL);
	i = 0;
	while (calc[i])
		i++;
	if (!(result = (char *)malloc(sizeof(char) * 36)))
		return (NULL);
	j = 35;
	while (j >= 0)
	{
		if (j == 8 || j == 17 || j == 26)
			result[j--] = '.';
		if (i >= 0)
			result[j--] = calc[i--];
		else
			result[j--] = '0';
	}
	return (result);
}

char			*ft_binary(int n, int dots)
{
	int		i;
	int		j;
	char	*calc;
	char	*nodots;

	if (dots == 1)
		return (ft_getdots(n));
	if (!(calc = ft_calc(n)))
		return (NULL);
	i = 0;
	while (calc[i])
		i++;
	if (!(nodots = (char *)malloc(sizeof(char) * 33)))
		return (NULL);
	j = 33;
	while (j >= 0)
	{
		if (i >= 0)
			nodots[j--] = calc[i--];
		else
			nodots[j--] = '0';
	}
	return (nodots);
}
