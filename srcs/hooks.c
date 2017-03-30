/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:29:38 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/30 14:16:02 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			red_cross(t_env *e)
{
	exit_prog(e, NULL);
	return (0);
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
	{
		e->zoom = 1.0;
		e->v = e->v_init;
		e->c = e->c_init;
	}
	if (keycode == UP)
		e->state.it_add = 1;
	if (keycode == DOWN)
		e->state.it_sub = 1;
	if (keycode == SPACE && e->state.pause == 0)
		e->state.pause = 1;
	else if (keycode == SPACE && e->state.pause == 1)
		e->state.pause = 0;
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
	if (keycode == UP)
		e->state.it_add = 0;
	if (keycode == DOWN)
		e->state.it_sub = 0;
	return (0);
}

int			mouse_hook(int keycode, int x, int y, t_env *e)
{
	if (keycode == 1)
		zoom_in(x, y, e);
	if (keycode == 2)
		zoom_out(x, y, e);
	return (0);
}

int			motion_notify(int x, int y, t_env *e)
{
	if (e->state.pause == 1)
		return (0);
	e->c.x = e->c_init.x + ((float)x - MAX_X / 2) / 1000;
	e->c.y = e->c_init.y + ((float)y - MAX_Y / 2) / 1000;
	return (0);
}
