/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:32:54 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/30 21:04:05 by hcaspar          ###   ########.fr       */
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

void				init_values(t_env *e)
{
	e->pu = 1;
	e->zoom = 1.0;
	e->v.x = -1.6;
	e->v.y = -1.6;
	e->v.z = fabs(e->v.x) + fabs(e->v.y);
	e->v.w = 100;
	(e->v_init) = e->v;
	e->c.x = 0.285;
	e->c.y = 0.01;
	(e->c_init) = e->c;
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
	state.pause = 0;
	return (state);
}

void				get_name(t_env *e, char *av)
{
	if (!ft_strcmp(av, "Mandel"))
		e->name = MANDEL;
	else if (!ft_strcmp(av, "Julia"))
		e->name = JULIA;
	else if (!ft_strcmp(av, "Ship"))
		e->name = SHIP;
	else
		exit_prog(e, "Choose a valid fractal\n");
}

int					main(int ac, char **av)
{
	t_env			*e;

	e = NULL;
	if (ac < 2)
		exit_prog(e, "Missing argument\n");
	e = init_env();
	e->state = init_states();
	new_window(e);
	init_image(e);
	get_name(e, av[1]);
	init_opencl(e, e->name);
	init_values(e);
	if (av[2] && !ft_strcmp(av[2], "cpu"))
		e->pu = 0;
	mlx_hook(e->mlx.win_ptr, 2, (1L << 0), key_press, e);
	mlx_hook(e->mlx.win_ptr, 3, (1L << 0), key_release, e);
	mlx_hook(e->mlx.win_ptr, 4, (1L << 2), mouse_hook, e);
	mlx_hook(e->mlx.win_ptr, 6, (1L << 6), motion_notify, e);
	mlx_hook(e->mlx.win_ptr, 17, (1L << 17), red_cross, e);
	mlx_loop_hook(e->mlx.mlx_ptr, redraw, e);
	mlx_loop(e->mlx.mlx_ptr);
	return (0);
}
