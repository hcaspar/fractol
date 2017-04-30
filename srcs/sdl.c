/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:33:46 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/30 19:35:09 by hcaspar          ###   ########.fr       */
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
		mouse_hook(event, event.button.x, event.button.y, e);
	if (event.type == SDL_MOUSEMOTION)
		motion_notify(event.motion.x, event.motion.y, e);
}

void			sdl_loop(t_env *e)
{
	while (SDL_PollEvent(&e->sdl.event) || 1)
	{
		redraw(e);
//		SDL_FillRect(e->sdl.screen, NULL, 0);
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
	e->sdl.screen = SDL_GetWindowSurface(e->sdl.p_win);
	e->sdl.image = SDL_CreateRGBSurfaceWithFormat(0, MAX_X, MAX_Y, 32, SDL_PIXELFORMAT_RGBA32);
	if (TTF_Init() < 0)
		exit_prog(e, "TTF init error\n");
	e->sdl.police = TTF_OpenFont("police.ttf", 22);
	if (!e->sdl.police)
		exit_prog(e, "TTF Open Font error\n");
	e->sdl.image_pos.x = 0;
	e->sdl.image_pos.y = 0;
	e->sdl.texte_pos.x = 15;
	e->sdl.texte_pos.y = 15;
	e->sdl.color.r = 0;
	e->sdl.color.g = 0;
	e->sdl.color.b = 0;
}
