/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:57:25 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/19 17:12:14 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				zoom_in(int x, int y, t_env *e)
{
	float			xscale;
	float			yscale;
	float			ztemp;
	float			xtemp;
	float			ytemp;

	ztemp = e->v.z;
	xtemp = e->v.x;
	ytemp = e->v.y;
	e->zoom *= 1.1;
	e->v.z = e->v_init.z / e->zoom;
	e->v.x += (ztemp - e->v.z) / 2;
	e->v.y += (ztemp - e->v.z) / 2;
	xscale = e->v.z / MAX_X;
	yscale = e->v.z / MAX_Y;
	x = (x - MAX_X / 2);
	y = (y - MAX_Y / 2);
	e->v.x += (x * (ztemp / MAX_X)) - (x * xscale);
	e->v.y += (y * (ztemp / MAX_Y)) - (y * yscale);
}

void				zoom_out(int x, int y, t_env *e)
{
	float			xscale;
	float			yscale;
	float			ztemp;
	float			xtemp;
	float			ytemp;

	ztemp = e->v.z;
	xtemp = e->v.x;
	ytemp = e->v.y;
	e->zoom /= 1.1;
	e->v.z = e->v_init.z / e->zoom;
	e->v.x += (ztemp - e->v.z) / 2;
	e->v.y += (ztemp - e->v.z) / 2;
	xscale = e->v.z / MAX_X;
	yscale = e->v.z / MAX_Y;
	x = (x - MAX_X / 2);
	y = (y - MAX_Y / 2);
	e->v.x += (x * (ztemp / MAX_X)) - (x * xscale);
	e->v.y += (y * (ztemp / MAX_Y)) - (y * yscale);
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
