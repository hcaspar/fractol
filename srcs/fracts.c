/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:25:54 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/18 14:43:48 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char				*mandel(cl_float4 v, char *tab, int size_line)
{
	int				x;
	int				y;
	float			zoom;
	float			i;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			zoom = SIZE / v.z;
			c_r = x / zoom + v.x;
			c_i = y / zoom + v.y;
			z_r = 0;
			z_i = 0;
			i = 0;
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i++;
			while (z_r * z_r + z_i * z_i < 4 && i < v.w)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			tab[x * 4 + y * size_line] = \
			(sin(0.016 * i + 2) * 230 + 25) * 1;
			tab[x * 4 + y * size_line + 1] = \
			(sin(0.016 * i + 3) * 230 + 25) * 2;
			tab[x * 4 + y * size_line + 2] = \
			(sin(0.016 * i + 4) * 230 + 25) * 3;
		}
	}
	return (tab);
}

char				*julia(cl_float4 v, char *tab, cl_float2 c, int size_line)
{
	int				x;
	int				y;
	float			zoom;
	float			i;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			zoom = SIZE / v.z;
			c_r = c.x;
			c_i = c.y;
			z_r = x / zoom + v.x;
			z_i = y / zoom + v.y;
			i = 0;
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i++;
			while (z_r * z_r + z_i * z_i < 4 && i < v.w)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			tab[x * 4 + y * size_line] = \
			(sin(0.016 * i + 2) * 230 + 25) * 1;
			tab[x * 4 + y * size_line + 1] = \
			(sin(0.016 * i + 3) * 230 + 25) * 2;
			tab[x * 4 + y * size_line + 2] = \
			(sin(0.016 * i + 4) * 230 + 25) * 3;
		}
	}
	return (tab);
}

char				*ship(cl_float4 v, char *tab, int size_line)
{
	int				x;
	int				y;
	float			zoom;
	float			i;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			zoom = SIZE / v.z;
			c_r = x / zoom + v.x;
			c_i = y / zoom + v.y;
			z_r = 0;
			z_i = 0;
			i = 0;
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * fabs(z_i * tmp) + c_i;
			i++;
			while (z_r * z_r + z_i * z_i < 4 && i < v.w)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * fabs(z_i * tmp) + c_i;
				i++;
			}
			tab[x * 4 + y * size_line] = \
			(sin(0.016 * i + 2) * 230 + 25) * 1;
			tab[x * 4 + y * size_line + 1] = \
			(sin(0.016 * i + 3) * 230 + 25) * 2;
			tab[x * 4 + y * size_line + 2] = \
			(sin(0.016 * i + 4) * 230 + 25) * 3;
		}
	}
	return (tab);
}
