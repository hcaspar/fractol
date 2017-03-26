/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:32:54 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/26 23:21:56 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_env				*init_env(void)
{
	t_env			*e;

	e = (t_env*)malloc(sizeof(t_env));
	if (e == NULL)
		exit_prog(e, "Malloc error\n");
	return (e);
}

cl_float4			init_values(void)
{
	cl_float4		v;

	v.x = -1.8;
	v.y = -1.2;
	v.z = 2.4;
	v.w = 50;
	return (v);
}

t_state				init_states(void)
{
	t_state			state;

	state.fwd = 0;
	state.back = 0;
	state.right = 0;
	state.left = 0;
	return (state);
}

int					main(int ac, char **av)
{
	t_env			*e;
	int				i;

	e = NULL;
	i = 1;
	if (ac < 2)
		exit_prog(e, "Missing argument\n");
	if (av[1])
	{
		e = init_env();
		e->state = init_states();
		init_opencl(e);
		new_window(e);
		init_image(e);
		e->v_init = init_values();
		e->v = e->v_init;
		draw(e, e->v);
	}
	mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, \
							e->mlx.image, 0, 0);
	mlx_hook(e->mlx.win_ptr, 2, (1L << 0), key_press, e);
	mlx_hook(e->mlx.win_ptr, 3, (1L << 0), key_release, e);
	mlx_hook(e->mlx.win_ptr, 17, (1L << 17), red_cross, e);
	mlx_loop_hook(e->mlx.mlx_ptr, redraw, e);
	mlx_loop(e->mlx.mlx_ptr);
	return (0);
}
