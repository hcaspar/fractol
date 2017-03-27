/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:55:52 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/27 21:12:15 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				put_pixel(int x, int y, t_color col, t_env *e)
{
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

void				draw(t_env *e, cl_float4 v)
{
	int				ret;
	int				i;
	int				x;
	int				y;
	t_color			color;

	i = -1;
	while (++i < (int)e->ocl.gws)
		e->v_tab[i] = v;
	ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.v_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_float4), e->v_tab, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(e->ocl.command_queue, e->ocl.kernel, 1, \
		NULL, &(e->ocl.gws), &(e->ocl.lws), 0, NULL, NULL);
	ret = clEnqueueReadBuffer(e->ocl.command_queue, e->ocl.tab_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_uchar3), e->tab, 0, NULL, NULL);
	i = -1;
	while (++i < (int)e->ocl.gws)
	{
		color = set_color(e->tab[i]);
		y = i / MAX_X;
		x = i % MAX_Y;
		put_pixel(x, y, color, e);
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
