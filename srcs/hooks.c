/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:29:38 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/18 14:44:00 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			key_press(SDL_Event event, t_env *e)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		exit_prog(e, NULL);
	if (event.key.keysym.sym == SDLK_w)
		e->state.fwd = 1;
	if (event.key.keysym.sym == SDLK_s)
		e->state.back = 1;
	if (event.key.keysym.sym == SDLK_d)
		e->state.right = 1;
	if (event.key.keysym.sym == SDLK_a)
		e->state.left = 1;
	if (event.key.keysym.sym == SDLK_r)
	{
		e->zoom = 1.0;
		e->v = e->v_init;
		e->c = e->c_init;
	}
	if (event.key.keysym.sym == SDLK_UP)
		e->state.it_add = 1;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->state.it_sub = 1;
	if (event.key.keysym.sym == SDLK_SPACE && e->state.pause == 0)
		e->state.pause = 1;
	else if (event.key.keysym.sym == SDLK_SPACE && e->state.pause == 1)
		e->state.pause = 0;
	return (0);
}

int			key_release(SDL_Event event, t_env *e)
{
	if (event.key.keysym.sym == SDLK_w)
		e->state.fwd = 0;
	if (event.key.keysym.sym == SDLK_s)
		e->state.back = 0;
	if (event.key.keysym.sym == SDLK_d)
		e->state.right = 0;
	if (event.key.keysym.sym == SDLK_a)
		e->state.left = 0;
	if (event.key.keysym.sym == SDLK_UP)
		e->state.it_add = 0;
	if (event.key.keysym.sym == SDLK_DOWN)
		e->state.it_sub = 0;
	return (0);
}

int			mouse_hook(SDL_Event event, int x, int y, t_env *e)
{
	if (event.button.button == SDL_BUTTON_LEFT)
		zoom_in(x, y, e);
	if (event.button.button == SDL_BUTTON_RIGHT)
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
