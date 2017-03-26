/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:49:42 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/29 15:35:06 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	compt;

	compt = 0;
	while (src[compt] && compt < n)
	{
		dst[compt] = src[compt];
		compt++;
	}
	while (compt < n)
	{
		dst[compt] = '\0';
		compt++;
	}
	return (dst);
}
