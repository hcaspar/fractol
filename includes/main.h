/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:45:14 by hcaspar           #+#    #+#             */
/*   Updated: 2017/03/27 17:43:36 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include "keys.h"
# include <stdlib.h>
# include <mlx.h>
# include <stdio.h>

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define MAX_X 860
# define MAX_Y 860

# define MAX_SOURCE_SIZE (0x100000)

typedef struct			s_color
{
	unsigned char		red;
	unsigned char		gre;
	unsigned char		blu;
}						t_color;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*image;
	char				*string;
	int					bpp;
	int					size_line;
	int					endian;
}						t_mlx;

typedef struct			s_ocl
{
	cl_context			context;
	cl_command_queue	command_queue;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				v_mem_obj;
	cl_mem				y_mem_obj;
	cl_mem				tab_mem_obj;
}						t_ocl;

typedef struct			s_state
{
	int					fwd;
	int					back;
	int					right;
	int					left;
}						t_state;

typedef struct			s_env
{
	t_mlx				mlx;
	t_ocl				ocl;
	t_state				state;
	cl_float4			v;
	cl_float4			v_init;
}						t_env;

void					exit_prog(t_env *e, char *msg);
int						red_cross(t_env *e);

void					new_window(t_env *e);
void					init_image(t_env *e);

void					draw(t_env *e, cl_float4 v);
int						redraw(t_env *e);

int						key_press(int keycode, t_env *e);
int						key_release(int keycode, t_env *e);
void					state_loop(t_env *e);

void					init_opencl(t_env *e);

#endif
