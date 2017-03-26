/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:06:39 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/29 15:34:29 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	compt;

	compt = 0;
	while (src[compt])
	{
		dst[compt] = src[compt];
		compt++;
	}
	dst[compt] = '\0';
	return (dst);
}
