#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#define		SIZE 1024

__kernel	void	mandel(__global double4 *v,
						   __global char *tab,
						   __global double2 *c)
{
	int				id;
	double			zoom;
	double			i;
	int				x;
	int				y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;

	id = get_global_id(0);
	y = (id / 4) / SIZE;
	x = (id / 4) % SIZE;
	zoom = SIZE / v[id / 4].z;
	c_r = x / zoom + v[id / 4].x;
	c_i = y / zoom + v[id / 4].y;
	z_r = 0;
	z_i = 0;
	i = 0;
	tmp = z_r;
	z_r = z_r * z_r - z_i * z_i + c_r;
	z_i = 2 * z_i * tmp + c_i;
	i++;
	while (z_r * z_r + z_i * z_i < 4 && i < v[id / 4].w)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	tab[id] = (sin(0.016 * i + id % 4 + 5) * 230 + 25) * ((id + 1) % 4);
}

__kernel	void	julia(__global double4 *v,
						  __global char *tab,
						  __global double2 *c)
{
	int				id;
	double			zoom;
	double			i;
	int				x;
	int				y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;

	id = get_global_id(0);
	y = (id / 4) / SIZE;
	x = (id / 4) % SIZE;
	zoom = SIZE / v[id / 4].z;
	c_r = c[id / 4].x;
	c_i = c[id / 4].y;
	z_r = x / zoom + v[id / 4].x;
	z_i = y / zoom + v[id / 4].y;
	i = 0;
	tmp = z_r;
	z_r = z_r * z_r - z_i * z_i + c_r;
	z_i = 2 * z_i * tmp + c_i;
	i++;
	while (z_r * z_r + z_i * z_i < 4 && i < v[id / 4].w)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	tab[id] = (sin(0.016 * i + id % 4 + 2) * 230 + 25) * ((id + 1) % 4);
}

__kernel	void	ship(__global double4 *v,
						 __global char *tab,
						 __global double2 *c)
{
	int				id;
	double			zoom;
	double			i;
	int				x;
	int				y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;

	id = get_global_id(0);
	y = (id / 4) / SIZE;
	x = (id / 4) % SIZE;
	zoom = SIZE / v[id / 4].z;
	c_r = x / zoom + v[id / 4].x;
	c_i = y / zoom + v[id / 4].y;
	z_r = 0;
	z_i = 0;
	i = 0;
	tmp = z_r;
	z_r = z_r * z_r - z_i * z_i + c_r;
	z_i = 2 * fabs(z_i * tmp) + c_i;
	i++;
	while (z_r * z_r + z_i * z_i < 4 && i < v[id / 4].w)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * fabs(z_i * tmp) + c_i;
		i++;
	}
	tab[id] = (sin(0.016 * i + id % 4 + 5) * 230 + 25) * ((id + 1) % 4);
}
