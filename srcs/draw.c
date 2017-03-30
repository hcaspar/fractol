/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:55:52 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/30 16:19:51 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				put_pixel(int i, t_color col, t_env *e)
{
	int				x;
	int				y;

	y = i / MAX_X;
	x = i % MAX_Y;
	e->mlx.string[x * 4 + y * e->mlx.size_line] = col.blu;
	e->mlx.string[x * 4 + y * e->mlx.size_line + 1] = col.gre;
	e->mlx.string[x * 4 + y * e->mlx.size_line + 2] = col.red;
}

t_color				set_color(cl_uchar3 tab)
{
	t_color			color;

	color.red = tab.x;
	color.gre = tab.y;
	color.blu = tab.z;
	return (color);
}

void				draw(t_env *e, cl_float4 v, cl_float2 c)
{
	int				ret;
	int				i;

	i = -1;
	while (++i < (int)e->ocl.gws)
	{
		e->v_tab[i] = v;
		e->c_tab[i] = c;
	}
	ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.v_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_float4), e->v_tab, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.c_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_float2), e->c_tab, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(e->ocl.command_queue, e->ocl.kernel, 1, \
		NULL, &(e->ocl.gws), &(e->ocl.lws), 0, NULL, NULL);
	ret = clEnqueueReadBuffer(e->ocl.command_queue, e->ocl.tab_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(char) * 4, e->mlx.string, \
		0, NULL, NULL);
}

int					redraw(t_env *e)
{
	mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.image);
	init_image(e);
	state_loop(e);
	draw(e, e->v, e->c);
	mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, \
							e->mlx.image, 0, 0);
	return (0);
}
