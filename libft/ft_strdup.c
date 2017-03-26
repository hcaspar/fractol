/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:07:09 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/18 18:07:10 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		compt;

	compt = 0;
	dup = (char *)malloc(sizeof(*dup) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (s1[compt])
	{
		dup[compt] = s1[compt];
		compt++;
	}
	dup[compt] = '\0';
	return (dup);
}
