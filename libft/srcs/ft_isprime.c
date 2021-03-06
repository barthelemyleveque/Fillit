/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:31:03 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/10 17:31:05 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprime(unsigned int nb)
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
