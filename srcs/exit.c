/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:07:06 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/18 19:38:29 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			finalization(t_env *e)
{
	cl_int		ret;

	ret = clFlush(e->ocl.command_queue);
	ret = clFinish(e->ocl.command_queue);
	ret = clReleaseKernel(e->ocl.kernel);
	ret = clReleaseProgram(e->ocl.program);
	ret = clReleaseMemObject(e->ocl.c_mem_obj);
	ret = clReleaseMemObject(e->ocl.v_mem_obj);
	ret = clReleaseMemObject(e->ocl.tab_mem_obj);
	ret = clReleaseCommandQueue(e->ocl.command_queue);
	ret = clReleaseContext(e->ocl.context);
}

void			exit_prog(t_env *e, char *msg)
{
	if (e)
	{
		finalization(e);
		if (e->v_tab)
			free(e->v_tab);
		if (e->c_tab)
			free(e->c_tab);
		SDL_FreeSurface(e->sdl.texte);
		if (e->sdl.p_win)
	    	SDL_DestroyWindow(e->sdl.p_win);
	    SDL_Quit();
		TTF_CloseFont(e->sdl.police);
		TTF_Quit();
		free(e);
	}
	if (msg)
		write(2, msg, ft_strlen(msg));
	exit(0);
}
