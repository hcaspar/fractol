/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:29:38 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/26 22:24:25 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			red_cross(t_env *e)
{
	exit_prog(e, NULL);
	return (0);
}

void		state_loop(t_env *e)
{
	if (e->state.fwd)
		e->v.y += 0.1;
	if (e->state.back)
		e->v.y -= 0.1;
	if (e->state.right)
		e->v.x -= 0.1;
	if (e->state.left)
		e->v.x += 0.1;
}

int			key_press(int keycode, t_env *e)
{
	keycode == ESC ? exit_prog(e, NULL) : 0;
	if (keycode == W)
		e->state.fwd = 1;
	if (keycode == S)
		e->state.back = 1;
	if (keycode == D)
		e->state.right = 1;
	if (keycode == A)
		e->state.left = 1;
	if (keycode == R)
		e->v = e->v_init;
	return (0);
}

int			key_release(int keycode, t_env *e)
{
	if (keycode == W)
		e->state.fwd = 0;
	if (keycode == S)
		e->state.back = 0;
	if (keycode == D)
		e->state.right = 0;
	if (keycode == A)
		e->state.left = 0;
	return (0);
}

int			redraw(t_env *e)
{
	mlx_destroy_image(e->mlx.mlx_ptr, e->mlx.image);
	init_image(e);
	state_loop(e);
	draw(e, e->v);
	mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, \
							e->mlx.image, 0, 0);
	return (0);
}
