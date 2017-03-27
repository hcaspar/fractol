/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:32:54 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/27 22:20:40 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_env				*init_env(void)
{
	t_env			*e;

	e = (t_env*)malloc(sizeof(t_env));
	if (e == NULL)
		exit_prog(e, "Malloc error\n");
	e->zoom = 1.0;
	return (e);
}

cl_float4			init_values(cl_float4 *v_init)
{
	cl_float4		v;

	v.x = -1.8;
	v.y = -1.2;
	v.z = 2.4;
	v.w = 50;
	*(v_init) = v;
	return (v);
}

t_state				init_states(void)
{
	t_state			state;

	state.fwd = 0;
	state.back = 0;
	state.right = 0;
	state.left = 0;
	state.it_add = 0;
	state.it_sub = 0;
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
	e = init_env();
	e->state = init_states();
	if (!ft_strcmp(av[1], "Mandel"))
		init_opencl(e, MANDEL);
	if (!ft_strcmp(av[1], "Julia"))
		init_opencl(e, JULIA);
	e->v = init_values(&e->v_init);
	new_window(e);
	mlx_hook(e->mlx.win_ptr, 2, (1L << 0), key_press, e);
	mlx_hook(e->mlx.win_ptr, 3, (1L << 0), key_release, e);
	mlx_hook(e->mlx.win_ptr, 17, (1L << 17), red_cross, e);
	mlx_hook(e->mlx.win_ptr, 4, (1L << 2), mouse_hook, e);
	mlx_loop_hook(e->mlx.mlx_ptr, redraw, e);
	mlx_loop(e->mlx.mlx_ptr);
	return (0);
}
