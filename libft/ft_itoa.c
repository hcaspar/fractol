/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:00:47 by hcaspar           #+#    #+#             */
/*   Updated: 2015/12/07 14:54:22 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_sub(int len, long n_cpy, char *str, int swap)
{
	while (len != swap)
	{
		str[len - 1] = (n_cpy % 10) + 48;
		n_cpy = n_cpy / 10;
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	long	n_cpy;
	char	*str;
	int		swap;

	len = 1;
	if (n < 0)
		len++;
	n_cpy = n;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		len++;
	}
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	swap = 0;
	if (n_cpy < 0)
	{
		n_cpy = -n_cpy;
		str[0] = '-';
		swap = 1;
	}
	ft_sub(len, n_cpy, str, swap);
	return (str);
}
