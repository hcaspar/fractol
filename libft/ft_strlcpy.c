/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:05:02 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/18 19:08:11 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	compt;

	compt = 0;
	while (src[compt] && compt < n)
	{
		dst[compt] = src[compt];
		compt++;
	}
	dst[compt] = '\0';
	return (ft_strlen(src));
}
