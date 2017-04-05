/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:33:46 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/05 21:02:48 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			sdl_hook(t_env *e, SDL_Event event)
{
	if (event.type == SDL_WINDOWEVENT)
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			exit_prog(e, NULL);
	if (event.type == SDL_KEYDOWN)
		key_press(event, e);
	if (event.type == SDL_KEYUP)
		key_release(event, e);
	if (event.type == SDL_MOUSEBUTTONDOWN)
		mouse_hook(event, x, y, e);
	if (event.type == SDL_MOUSEMOTION)
		motion_notify(event.motion.x, event.motion.y, e);

}

void			sdl_loop(t_env *e)
{
	while (SDL_PollEvent(&e->sdl.event) || 1)
	{
		redraw(e);
		sdl_hook(e, e->sdl.event);
	}
}

void			init_sdl(t_env *e)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
		exit_prog(e, "SDL init error\n");
    e->sdl.p_win = NULL;
    e->sdl.p_win = SDL_CreateWindow("fractol", SDL_WINDOWPOS_UNDEFINED, \
		SDL_WINDOWPOS_UNDEFINED, MAX_X, MAX_Y, SDL_WINDOW_SHOWN);
    if (!e->sdl.p_win)
		exit_prog(e, "SDL window error\n");
	e->sdl.surf = SDL_GetWindowSurface(e->sdl.p_win);
}
