/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:22:33 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/29 18:32:28 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (src < dst)
	{
		while (len > 0)
		{
			len--;
			dstcpy[len] = srccpy[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
