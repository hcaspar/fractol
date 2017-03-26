/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:58:37 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/26 10:38:06 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	size_t			compt;

	compt = 0;
	b2 = (unsigned char*)b;
	while (compt < len)
	{
		b2[compt] = (unsigned char)c;
		compt++;
	}
	return (b);
}
