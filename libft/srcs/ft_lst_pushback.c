/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:32:51 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/14 16:21:35 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pushback(t_list *lst, void *content, size_t content_size)
{
	t_list	*new;
	t_list	*buff;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->content_size = content_size;
	new->next = NULL;
	if (!lst)
		return (new);
	buff = lst;
	while (buff->next)
		buff = buff->next;
	buff->next = new;
	return (lst);
}
