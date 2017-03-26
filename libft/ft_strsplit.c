/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 21:07:33 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/14 14:07:06 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_dub(char const *s, char c, char **tab, int nb)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			if ((tab[nb] = (char*)malloc(sizeof(char) * (j + 1))) == NULL)
				return (NULL);
			j = -1;
			while (s[i + ++j] != c && s[i + j] != '\0')
				tab[nb][j] = s[i + j];
			tab[nb++][j] = '\0';
			i = i + j;
		}
		else
			i++;
	}
	tab[nb] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb;
	char	**tab;

	i = 0;
	nb = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if ((tab = (char**)malloc(sizeof(char*) * (nb + 1))) == NULL)
		return (NULL);
	i = 0;
	nb = 0;
	ft_dub(s, c, tab, nb);
	return (tab);
}
