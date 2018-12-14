/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:53:55 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/12 19:02:47 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_delfront(t_list *lst)
{
	t_list	*element;

	if (!lst)
		return (NULL);
	if (!(element = (t_list *)malloc(sizeof(*element))))
		return (NULL);
	element = lst->next;
	free(lst);
	lst = NULL;
	return (element);
}
