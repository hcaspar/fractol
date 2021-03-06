/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 22:46:32 by hcaspar           #+#    #+#             */
/*   Updated: 2017/04/30 19:12:53 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void 					init_ws(t_env *e)
{
	e->ocl.gws = MAX_X * MAX_Y;
	e->ocl.lws = 1024;
	while (e->ocl.lws > e->ocl.gws || e->ocl.gws % e->ocl.lws != 0)
		e->ocl.lws /= 2;
	e->v_tab = (cl_float4*)malloc(sizeof(cl_float4) * e->ocl.gws);
	if (e->v_tab == NULL)
		exit_prog(e, "Malloc error\n");
	e->c_tab = (cl_float2*)malloc(sizeof(cl_float2) * e->ocl.gws);
	if (e->c_tab == NULL)
		exit_prog(e, "Malloc error\n");
}

void					init_opencl(t_env *e, int name)
{
	cl_device_id		device_id = NULL;
	cl_platform_id		platform_id = NULL;
	cl_uint				ret_num_devices;
	cl_uint				ret_num_platforms;
	cl_int				ret;

	e->ocl.context = NULL;
	e->ocl.command_queue = NULL;
	e->ocl.program = NULL;
	e->ocl.kernel = NULL;
	e->ocl.v_mem_obj = NULL;
	e->ocl.c_mem_obj = NULL;

	init_ws(e);

	FILE *fp;
	char fileName[] = "srcs/kernel.cl";
	char *source_str;
	size_t source_size;

		/* Load the source code containing the kernel*/
	fp = fopen(fileName, "r");
	if (!fp)
	{
		printf("Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);

		/* Get Platform and Device Info */
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

		/* Create OpenCL context */
	e->ocl.context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

		/* Create Command Queue */
	e->ocl.command_queue = clCreateCommandQueue(e->ocl.context, device_id, 0, &ret);

		/* Create Memory Buffer */

	e->ocl.v_mem_obj = clCreateBuffer(e->ocl.context, CL_MEM_READ_ONLY,
			e->ocl.gws * sizeof(cl_float4), NULL, &ret);
	e->ocl.tab_mem_obj = clCreateBuffer(e->ocl.context, CL_MEM_WRITE_ONLY,
            e->ocl.gws * sizeof(cl_uint), NULL, &ret);
	e->ocl.c_mem_obj = clCreateBuffer(e->ocl.context, CL_MEM_READ_ONLY,
			e->ocl.gws * sizeof(cl_float2), NULL, &ret);

		/* Create Kernel Program from the source */
	e->ocl.program = clCreateProgramWithSource(e->ocl.context, 1,
		(const char **)&source_str,	(const size_t *)&source_size, &ret);
	if (source_str)
		free(source_str);

		/* Build Kernel Program */
	ret = clBuildProgram(e->ocl.program, 1, &device_id, NULL, NULL, NULL);

		/* Create OpenCL Kernel */
	if (name == MANDEL)
		e->ocl.kernel = clCreateKernel(e->ocl.program, "mandel", &ret);
	if (name == JULIA)
		e->ocl.kernel = clCreateKernel(e->ocl.program, "julia", &ret);
	if (name == SHIP)
		e->ocl.kernel = clCreateKernel(e->ocl.program, "ship", &ret);

		/* Set OpenCL Kernel Parameters */
	ret = clSetKernelArg(e->ocl.kernel, 0, sizeof(cl_mem), (void *)&(e->ocl.v_mem_obj));
	ret = clSetKernelArg(e->ocl.kernel, 1, sizeof(cl_mem), (void *)&(e->ocl.tab_mem_obj));
	ret = clSetKernelArg(e->ocl.kernel, 2, sizeof(cl_mem), (void *)&(e->ocl.c_mem_obj));
}
