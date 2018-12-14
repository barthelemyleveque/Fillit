/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:05:39 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/14 16:28:18 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_putstr(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		ft_putstr("Rien a afficher, la liste est vide.\n");
	while (lst)
	{
		ft_putchar('(');
		ft_putnbr(i++);
		ft_putstr("e) element [");
		ft_putstr(lst->content);
		ft_putstr("] size = ");
		ft_putnbr(lst->content_size);
		ft_putstr(" | ");
		if (!lst->next)
			ft_putstr("Fin!\n");
		lst = lst->next;
	}
}
