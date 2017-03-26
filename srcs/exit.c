/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:07:06 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/26 23:24:51 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			finalization(t_env *e)
{
	cl_int		ret;

	ret = clFlush(e->ocl.command_queue);
	ret = clFinish(e->ocl.command_queue);
	ret = clReleaseKernel(e->ocl.kernel);
	ret = clReleaseProgram(e->ocl.program);
	ret = clReleaseMemObject(e->ocl.v_mem_obj);
	ret = clReleaseCommandQueue(e->ocl.command_queue);
	ret = clReleaseContext(e->ocl.context);
}

void			exit_prog(t_env *e, char *msg)
{
	if (e)
	{
		finalization(e);
		if (e->mlx.image)
			mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.image);
		if (e->mlx.win_ptr)
			mlx_destroy_window(e->mlx.mlx_ptr, e->mlx.win_ptr);
		free(e);
	}
	if (msg)
		write(2, msg, ft_strlen(msg));
	exit(0);
}

void			new_window(t_env *e)
{
	e->mlx.mlx_ptr = mlx_init();
	if (e->mlx.mlx_ptr == NULL)
		exit_prog(e, "Mlx error\n");
	e->mlx.win_ptr = mlx_new_window(e->mlx.mlx_ptr, MAX_X, MAX_Y, "fractol");
	if (e->mlx.win_ptr == NULL)
		exit_prog(e, "Mlx error\n");
}

void			init_image(t_env *e)
{
	e->mlx.image = mlx_new_image(e->mlx.mlx_ptr, MAX_X, MAX_Y);
	if (e->mlx.image == NULL)
		exit_prog(e, "Mlx error\n");
	e->mlx.string = mlx_get_data_addr(e->mlx.image, &e->mlx.bpp, \
									&e->mlx.size_line, &e->mlx.endian);
	if (e->mlx.string == NULL)
		exit_prog(e, "Mlx error\n");
}
