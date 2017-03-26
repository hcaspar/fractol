/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:42:10 by hcaspar           #+#    #+#             */
/*   Updated: 2015/11/28 12:41:00 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		nb;
	int		i;
	int		sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
	{
		if (str[i] == '\r' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	i--;
	while (str[++i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i] - 48;
	return (nb * sign);
}
