/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:57:25 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/30 14:15:58 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				zoom_in(int x, int y, t_env *e)
{
	float			scale;
	float			ztemp;

	ztemp = e->v.z;
	e->zoom *= 1.1;
	e->v.z = e->v_init.z / e->zoom;
	e->v.x += (ztemp - e->v.z) / 2;
	e->v.y += (ztemp - e->v.z) / 2;
	x = x - MAX_X / 2;
	y = y - MAX_Y / 2;
	scale = e->v.z / MAX_X;
	e->v.x += x * scale;
	e->v.y += y * scale;
}

void				zoom_out(int x, int y, t_env *e)
{
	float			scale;
	float			ztemp;

	ztemp = e->v.z;
	e->zoom /= 1.1;
	e->v.z = e->v_init.z / e->zoom;
	e->v.x += (ztemp - e->v.z) / 2;
	e->v.y += (ztemp - e->v.z) / 2;
	x = x - MAX_X / 2;
	y = y - MAX_Y / 2;
	scale = e->v.z / MAX_X;
}

void				state_loop(t_env *e)
{
	if (e->state.fwd)
		e->v.y -= 0.05 / e->zoom;
	if (e->state.back)
		e->v.y += 0.05 / e->zoom;
	if (e->state.right)
		e->v.x += 0.05 / e->zoom;
	if (e->state.left)
		e->v.x -= 0.05 / e->zoom;
	if (e->state.it_add)
		e->v.w += 5.0;
	if (e->state.it_sub && e->v.w > 5.0)
		e->v.w -= 5.0;
}
