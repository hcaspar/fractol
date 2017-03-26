/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:07:31 by hcaspar           #+#    #+#             */
/*   Updated: 2016/05/23 17:52:18 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	compt;
	size_t	i;

	i = ft_strlen(s1);
	if (i > n)
		i = n;
	compt = 0;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (!dup)
		return (NULL);
	while (s1[compt] && compt < n)
	{
		dup[compt] = s1[compt];
		compt++;
	}
	dup[compt] = '\0';
	return (dup);
}
