/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:08:21 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/20 13:39:04 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *mylst;

	if (!(mylst = ((t_list*)malloc(sizeof(t_list)))))
		return (NULL);
	if (content == NULL)
	{
		mylst->content = NULL;
		mylst->content_size = 0;
	}
	else
	{
		if (!(mylst->content = malloc(content_size)))
		{
			free(mylst);
			return (NULL);
		}
		mylst->content = ft_memalloc(content_size);
		mylst->content = ft_memcpy(mylst->content, content, content_size);
		mylst->content_size = content_size;
	}
	mylst->next = NULL;
	return (mylst);
}
