/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzmuda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 14:40:51 by bzmuda            #+#    #+#             */
/*   Updated: 2016/11/19 15:15:14 by bzmuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		deb;
	int		fin;
	char	**tab;

	tab = NULL;
	i = 0;
	j = 0;
	if (!(s && (tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s))))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		deb = i;
		while (s[i] && s[i] != c)
			i++;
		fin = i;
		if (fin > deb)
			tab[j++] = ft_strsub(s, deb, (fin - deb));
	}
	tab[j] = NULL;
	return (tab);
}
