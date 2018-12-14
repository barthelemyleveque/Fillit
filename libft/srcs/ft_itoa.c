/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:08:18 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/13 15:02:29 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long int	ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	return (n * ft_pow(n, p - 1));
}

static void		ft_negative(int *i, long long int *nb, int *neg)
{
	*i = 1;
	*neg = 0;
	if (*nb < 0)
	{
		*neg = 1;
		*nb *= -1;
	}
}

char			*ft_itoa(int n)
{
	long long int	nb;
	int				i;
	int				neg;
	char			*result;

	nb = n;
	ft_negative(&i, &nb, &neg);
	while (ft_pow(10, i) - 1 < nb)
		i++;
	if (!(result = (char *)malloc(sizeof(char) * (i + neg) + 1)))
		return (NULL);
	result[i + neg] = '\0';
	if (neg)
		result[0] = '-';
	while (i-- > 0)
	{
		result[i + neg] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (result);
}
