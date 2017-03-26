/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:44:55 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/14 14:06:06 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t') && j > 0)
		j--;
	len = j - i;
	if (len < 0)
		len = 0;
	if ((new = ft_strnew(len)) == NULL)
		return (NULL);
	new = ft_strsub(s, i, len);
	return (new);
}
