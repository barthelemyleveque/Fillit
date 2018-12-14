/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:32:06 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/10 11:32:51 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_prime(unsigned int nb)
{
	unsigned int i;

	i = 1;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (++i <= nb / 2)
		if (nb % i == 0)
			return (0);
	return (1);
}

int			ft_nprime(unsigned int nb)
{
	while (ft_is_prime(nb++) != 1)
	{
	}
	return (--nb);
}
