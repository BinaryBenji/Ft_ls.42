/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:33:58 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/11 14:33:42 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	unsigned char		*str2;

	i = 0;
	str1 = ((unsigned char *)dest);
	str2 = ((unsigned char *)src);
	while (n > 0)
	{
		n--;
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
