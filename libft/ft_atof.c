/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:10:26 by hcaspar           #+#    #+#             */
/*   Updated: 2017/01/18 18:16:04 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	assign(const char *str, int i, double nb)
{
	int		j;

	j = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb + ((str[i] - 48.0) / ft_pow(10, j));
			i++;
			j++;
		}
	}
	return (nb);
}

double			ft_atof(const char *str)
{
	double	nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while (ft_isspace(str[i]) && !ft_isdigit(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	nb = assign(str, i, nb);
	return (nb * sign);
}
