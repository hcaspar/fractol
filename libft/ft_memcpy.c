/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:16:44 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/29 15:29:41 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		compt++;
	}
	return (dst);
}
