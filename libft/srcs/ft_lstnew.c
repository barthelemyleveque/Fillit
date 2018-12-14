/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzimmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:47:37 by thzimmer          #+#    #+#             */
/*   Updated: 2018/11/12 15:41:04 by thzimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	size_t	i;

	i = 0;
	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	if (content)
	{
		if (!(new->content = malloc(sizeof(int) * content_size)))
			return (NULL);
		while (i < content_size)
		{
			((int *)new->content)[i] = ((int *)content)[i];
			new->content_size = content_size;
			i++;
		}
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	return (new);
}
