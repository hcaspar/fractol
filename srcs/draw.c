/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:55:52 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/26 23:33:36 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				put_pixel(int x, int y, t_color col, t_env *e)
{
	e->mlx.string[x * 4 + y * e->mlx.size_line] = col.blu;
	e->mlx.string[x * 4 + y * e->mlx.size_line + 1] = col.gre;
	e->mlx.string[x * 4 + y * e->mlx.size_line + 2] = col.red;
}

t_color				set_color(float r)
{
	t_color			color;

	color.red = 255 * r;
	color.gre = 255 - 255 * r;
	color.blu = 255 * r;
	return (color);
}

void				draw(t_env *e, cl_float4 v)
{
	float			x;
	float			y;
	float			zoom_x;
	float			zoom_y;
	float			i;
	t_color			color;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	zoom_x = MAX_X / e->v.z;
	zoom_y = MAX_Y / e->v.z;
	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			c_r = x / zoom_x + v.x;
			c_i = y / zoom_y + v.y;
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
			color = set_color(i / v.w);
			put_pixel(x, y, color, e);
		}
	}
}
//
// /* Execute OpenCL Kernel */
// ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0,
// 	MAX_X * sizeof(float4), A, 0, NULL, NULL);
// size_t global_item_size = MAX_X;
// size_t local_item_size = MAX_X;
// ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
// &global_item_size, &local_item_size, 0, NULL, NULL);
//
// /* Copy results from the memory buffer */
// ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0,
// MEM_SIZE * sizeof(int), C, 0, NULL, NULL);
//
// /* Display Result */
// for (i = 0; i < MEM_SIZE; i++)
// printf("%d\n", C[i]);
