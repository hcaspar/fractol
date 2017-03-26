/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:45:32 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/29 15:31:33 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			compt;
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	compt = 0;
	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	while (compt < n)
	{
		dstcpy[compt] = srccpy[compt];
		if (srccpy[compt] == (unsigned char)c)
		{
			return ((void*)&dst[compt + 1]);
		}
		compt++;
	}
	return (NULL);
}
