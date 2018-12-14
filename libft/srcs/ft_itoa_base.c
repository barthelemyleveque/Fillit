/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:20:42 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/14 17:58:11 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static long int	ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	return (n * ft_pow(n, p - 1));
}

static void		ft_negative(int *i, long long int *nb, int *neg, int base)
{
	*i = 1;
	*neg = 0;
	if (*nb < 0)
	{
		if (base == 10)
			*neg = 1;
		*nb *= -1;
	}
}

char			*ft_itoa_base(int n, int base)
{
	long long int	nb;
	int				i;
	int				neg;
	char			*result;

	if (base < 2 || base > 16)
		return ("Please select a base between 2 (binary) and 16 (hexdecimal).");
	nb = n;
	ft_negative(&i, &nb, &neg, base);
	while (ft_pow(base, i) - 1 < nb)
		i++;
	if (!(result = (char *)malloc(sizeof(char) * i + 1 + neg)))
		return (NULL);
	result[i + neg] = '\0';
	if (neg)
		result[0] = '-';
	while (i-- > 0)
	{
		result[i + neg] = nb % base + (nb % base > 9 ? 'A' - 10 : '0');
		nb = nb / base;
	}
	return (result);
}
