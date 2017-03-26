/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:21:37 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/26 13:37:24 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	compt;
	char	*s2;

	compt = 0;
	s2 = (char *)s;
	while (compt < n)
	{
		if (s2[compt] == (char)c)
			return ((void*)&s2[compt]);
		compt++;
	}
	return (NULL);
}
