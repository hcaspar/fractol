/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:05:40 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/27 17:05:32 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		compt;
	char	*scpy;

	scpy = (char *)s;
	compt = ft_strlen(s);
	if ((char)c == '\0')
		return (&scpy[compt]);
	while (compt != -1)
	{
		if (scpy[compt] == (char)c)
			return (&scpy[compt]);
		compt--;
	}
	return (NULL);
}
