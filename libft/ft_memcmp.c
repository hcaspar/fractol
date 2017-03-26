/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:39:15 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/26 14:07:04 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			compt;
	unsigned char	*s1cpy;
	unsigned char	*s2cpy;

	s1cpy = (unsigned char*)s1;
	s2cpy = (unsigned char*)s2;
	compt = 0;
	while (compt < n)
	{
		if (s1cpy[compt] != s2cpy[compt])
			return (s1cpy[compt] - s2cpy[compt]);
		compt++;
	}
	return (0);
}
