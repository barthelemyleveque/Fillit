/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:02:41 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/10 11:03:28 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	char c;

	c = '\n';
	if (!s)
	{
		write(fd, &c, 1);
		return ;
	}
	while (*s)
		write(fd, s++, 1);
	write(fd, &c, 1);
}
