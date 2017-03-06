/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:42:41 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/20 15:30:53 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int		ft_cptchiffre(long n)
{
	int i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char		ft_moins(long nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

char			*ft_itoa(int n)
{
	long	nb;
	size_t	cpt;
	char	*str;
	int		moins;

	nb = n;
	moins = ft_moins(nb);
	cpt = ft_cptchiffre(nb);
	if (!(str = ft_strnew(cpt + moins)))
		return (NULL);
	if (moins)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (cpt > 0)
	{
		str[cpt + moins - 1] = (nb % 10) + '0';
		cpt--;
		nb = nb / 10;
	}
	return (str);
}
