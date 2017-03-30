/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:55:52 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/30 21:03:32 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				draw_cpu(t_env *e, cl_double4 v, cl_double2 c)
{
	if (e->name == JULIA)
		e->mlx.string = julia(v, e->mlx.string, c, e->mlx.size_line);
	if (e->name == SHIP)
		e->mlx.string = ship(v, e->mlx.string, e->mlx.size_line);
}

void				draw_gpu(t_env *e, cl_double4 v, cl_double2 c)
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
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_double4), e->v_tab, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.c_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_double2), e->c_tab, 0, NULL, NULL);
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
	if (e->pu == 1)
		draw_gpu(e, e->v, e->c);
	else
		draw_cpu(e, e->v, e->c);
	mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, \
							e->mlx.image, 0, 0);
	return (0);
}
