/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:54:56 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/26 14:49:56 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		compt;
	char	*scpy;

	scpy = (char *)s;
	compt = 0;
	while (scpy[compt])
	{
		if (scpy[compt] == (char)c)
			return (&scpy[compt]);
		compt++;
	}
	if ((char)c == '\0')
		return (&scpy[compt]);
	return (NULL);
}
