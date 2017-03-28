/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:57:25 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/28 11:22:39 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				zoom_in(int x, int y, t_env *e)
{
	e->zoom *= 1.1;
	x = 0;
	y = 0;
	e->v.z = e->v_init.z * e->zoom;
	e->v.x = e->v_init.x * e->zoom;
	e->v.y = e->v_init.y * e->zoom;
}

void				zoom_out(int x, int y, t_env *e)
{
	e->zoom /= 1.1;
	x = 0;
	y = 0;
	e->v.z = e->v_init.z * e->zoom;
	e->v.x = e->v_init.x * e->zoom;
	e->v.y = e->v_init.y * e->zoom;
}

void				state_loop(t_env *e)
{
	if (e->state.fwd)
		e->v.y -= 0.1 * e->zoom;
	if (e->state.back)
		e->v.y += 0.1 * e->zoom;
	if (e->state.right)
		e->v.x += 0.1 * e->zoom;
	if (e->state.left)
		e->v.x -= 0.1 * e->zoom;
	if (e->state.it_add)
		e->v.w += 1.0;
	if (e->state.it_sub && e->v.w > 1.0)
		e->v.w -= 1.0;
}
