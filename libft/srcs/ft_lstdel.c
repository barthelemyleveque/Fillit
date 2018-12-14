/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:09:04 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/12 19:01:33 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buff;
	t_list	*suiv;

	if (!del)
		return ;
	buff = *alst;
	while (buff)
	{
		suiv = buff->next;
		del((buff->content), (buff->content_size));
		free(buff);
		buff = suiv;
	}
	*alst = NULL;
}
