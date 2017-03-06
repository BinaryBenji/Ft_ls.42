/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:32:13 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/11 11:32:51 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t lendest;
	size_t lensrc;

	lendest = 0;
	lensrc = 0;
	i = 0;
	while (dest[lendest] != '\0')
		lendest++;
	while (src[lensrc] != '\0')
		lensrc++;
	if (size < lendest)
		return (lensrc + size);
	while (src[i] != '\0' && (lendest + 1 + i) < size)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}
