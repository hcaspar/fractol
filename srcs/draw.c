/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:55:52 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/27 17:49:55 by hcaspar          ###   ########.fr       */
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
	int				ret;
	int				x;
	cl_int			y;
	t_color			color;
	cl_float		tab[MAX_X];
	cl_float4		v_tab[MAX_X];
	cl_int			y_tab[MAX_X];
	size_t			global_item_size;
	size_t			local_item_size;

	global_item_size = MAX_X;
	local_item_size = MAX_X;
	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			v_tab[x] = v;
			y_tab[x] = y;
		}
		/* Execute OpenCL Kernel */
		ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.v_mem_obj, CL_TRUE, 0,	MAX_X * sizeof(cl_float4), v_tab, 0, NULL, NULL);
		ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.y_mem_obj, CL_TRUE, 0,	MAX_X * sizeof(cl_int), y_tab, 0, NULL, NULL);
		ret = clEnqueueNDRangeKernel(e->ocl.command_queue, e->ocl.kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

		/* Copy results from the memory buffer */
		ret = clEnqueueReadBuffer(e->ocl.command_queue, e->ocl.tab_mem_obj, CL_TRUE, 0,	MAX_X * sizeof(float), tab, 0, NULL, NULL);
		x = -1;
		while (++x < MAX_X)
		{
			color = set_color(tab[x]);
			put_pixel(x, y, color, e);
		}
	}
}

int					redraw(t_env *e)
{
	init_image(e);
	state_loop(e);
	draw(e, e->v);
	mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, \
							e->mlx.image, 0, 0);
	mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.image);
	return (0);
}
