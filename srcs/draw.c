/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:55:52 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/18 14:44:04 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void				draw_cpu(t_env *e, cl_float4 v, cl_float2 c)
{
	if (e->name == MANDEL)
		e->sdl.surf->pixels = mandel(v, e->sdl.surf->pixels, e->sdl.surf->pitch);
	if (e->name == JULIA)
		e->sdl.surf->pixels = julia(v, e->sdl.surf->pixels, c, e->sdl.surf->pitch);
	if (e->name == SHIP)
		e->sdl.surf->pixels = ship(v, e->sdl.surf->pixels, e->sdl.surf->pitch);
}

void				draw_gpu(t_env *e, cl_float4 v, cl_float2 c)
{
	int				ret;
	int				i;

	i = -1;
	while (++i < (int)e->ocl.gws)
	{
		e->v_tab[i] = v;
		e->c_tab[i] = c;
	}
	ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.v_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_float4), e->v_tab, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(e->ocl.command_queue, e->ocl.c_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(cl_float2), e->c_tab, 0, NULL, NULL);
	ret = clEnqueueNDRangeKernel(e->ocl.command_queue, e->ocl.kernel, 1, \
		NULL, &(e->ocl.gws), &(e->ocl.lws), 0, NULL, NULL);
	ret = clEnqueueReadBuffer(e->ocl.command_queue, e->ocl.tab_mem_obj, \
		CL_TRUE, 0, e->ocl.gws * sizeof(char) * 4, e->sdl.surf->pixels, \
		0, NULL, NULL);
}

char				*draw_fps(float *oldtime)
{
	float			delta;
	float			newtime;
	char			*tmp;

	tmp = NULL;
	newtime = (float)clock();
	delta = (float)(newtime - *oldtime) / CLOCKS_PER_SEC;
	*oldtime = newtime;
	tmp = ft_itoa((int)(1.0 / delta));
	return (tmp);
}

void				redraw(t_env *e)
{
	char			*tmp;

	state_loop(e);
	if (e->pu == 1)
		draw_gpu(e, e->v, e->c);
	else
		draw_cpu(e, e->v, e->c);
	SDL_UpdateWindowSurface(e->sdl.p_win);
	tmp = draw_fps(&e->oldtime);
	if (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
	}
}
