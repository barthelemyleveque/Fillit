/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:53:49 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/12 19:03:09 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_delback(t_list *lst)
{
	t_list	*buff;
	t_list	*avant;

	if (!lst)
		return (NULL);
	if (!lst->next)
	{
		free(lst);
		lst = NULL;
		return (NULL);
	}
	avant = lst;
	buff = lst;
	while (buff->next)
	{
		avant = buff;
		buff = buff->next;
	}
	avant->next = NULL;
	free(buff);
	buff = NULL;
	return (lst);
}
