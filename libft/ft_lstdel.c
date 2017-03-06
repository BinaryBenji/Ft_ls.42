/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:45:47 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/20 13:55:56 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *prolist;

	list = *alst;
	while (list)
	{
		prolist = list->next;
		del(list->content, list->content_size);
		free(list);
		list = prolist;
	}
	*alst = NULL;
}
