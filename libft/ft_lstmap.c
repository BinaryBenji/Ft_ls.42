/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:57:02 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/20 14:05:51 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mylst;

	if (lst)
	{
		while (lst)
		{
			mylst = f(lst);
			mylst->next = ft_lstmap(lst->next, f);
			return (mylst);
		}
	}
	return (NULL);
}
