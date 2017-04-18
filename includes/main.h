/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:45:14 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/18 20:06:25 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define MAX_X 1024
# define MAX_Y 1024
# define SIZE 1024

# define MANDEL 1
# define JULIA 2
# define SHIP 3

# define MAX_SOURCE_SIZE (0x100000)

typedef struct			s_color
{
	unsigned char		red;
	unsigned char		gre;
	unsigned char		blu;
}						t_color;

typedef struct			s_sdl
{
	SDL_Window			*p_win;
	SDL_Event			event;
	SDL_Surface			*surf;
	SDL_Surface			*texte;
	TTF_Font			*police;
	SDL_Rect			position;
	SDL_Color			color;
}						t_sdl;

typedef struct			s_ocl
{
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				v_mem_obj;
	cl_mem				c_mem_obj;
	cl_mem				tab_mem_obj;
	size_t				gws;
	size_t				lws;
}						t_ocl;

typedef struct			s_state
{
	int					fwd;
	int					back;
	int					right;
	int					left;
	int					it_add;
	int					it_sub;
	int					pause;
}						t_state;

typedef struct			s_env
{
	t_sdl				sdl;
	t_ocl				ocl;
	t_state				state;
	float				oldtime;
	int					name;
	int					pu;
	cl_float4			v;
	cl_float4			v_init;
	cl_float2			c;
	cl_float2			c_init;
	cl_float2			*c_tab;
	cl_float4			*v_tab;
	float				zoom;
}						t_env;

void					exit_prog(t_env *e, char *msg);

void					redraw(t_env *e);

int						mouse_hook(SDL_Event event, int x, int y, t_env *e);
int						motion_notify(int x, int y, t_env *e);
int						key_press(SDL_Event event, t_env *e);
int						key_release(SDL_Event event, t_env *e);
void					state_loop(t_env *e);

void					zoom_in(int x, int y, t_env *e);
void					zoom_out(int x, int y, t_env *e);

void					init_opencl(t_env *e, int name);

char					*mandel(cl_float4 v, char *tab, int size_line);
char					*julia(cl_float4 v, char *tab, cl_float2 c, \
								int size_line);
char					*ship(cl_float4 v, char *tab, int size_line);

void					init_sdl(t_env *e);
void					sdl_loop(t_env *e);

#endif
