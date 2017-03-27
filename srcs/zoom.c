/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 21:30:14 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/27 22:00:00 by hcaspar          ###   ########.fr       */
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
