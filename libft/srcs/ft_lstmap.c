/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:55:13 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/12 19:02:05 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*debut;
	t_list	*element;
	t_list	*buff;
	t_list	*new;

	if (!f)
		return (NULL);
	if (!(element = (t_list *)malloc(sizeof(*element))))
		return (NULL);
	element = f(lst);
	debut = element;
	buff = lst->next;
	while (buff)
	{
		if (!(new = (t_list *)malloc(sizeof(*new))))
			return (NULL);
		new = f(buff);
		element->next = new;
		element = element->next;
		buff = buff->next;
	}
	new->next = NULL;
	return (debut);
}
