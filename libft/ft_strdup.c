/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:56:54 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/11 09:57:53 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
