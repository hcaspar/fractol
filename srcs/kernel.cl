#define		SIZE 1024

__kernel	void	mandel(__global float4 *v,
						   __global char *tab,
						   __global float2 *c)
{
	int				id;
	float			zoom;
	float			i;
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

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
	tab[id] = (sin(0.016 * i + id % 4 + 2) * 230 + 25) * ((id + 1) % 4);
}

__kernel	void	julia(__global float4 *v,
						  __global uint *tab,
						  __global float2 *c)
{
	int				id;
	float			zoom;
	float			i;
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;
	uint			color;

	id = get_global_id(0);
	y = id / SIZE;
	x = id % SIZE;
	zoom = SIZE / v[id].z;
	c_r = c[id].x;
	c_i = c[id].y;
	z_r = x / zoom + v[id].x;
	z_i = y / zoom + v[id].y;
	i = 0;
	tmp = z_r;
	z_r = z_r * z_r - z_i * z_i + c_r;
	z_i = 2 * z_i * tmp + c_i;
	i++;
	while (z_r * z_r + z_i * z_i < 4 && i < v[id].w)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	color = 255.0;
	color = (color << 8) + (sin(0.016 * i + id % 4 + 2) * 230.0 + 25.0) * ((id + 1) % 4);
	color = (color << 8) + (sin(0.016 * i + (id + 1) % 4 + 2) * 230.0 + 25.0) * ((id + 2) % 4);
	color = (color << 8) + (sin(0.016 * i + (id + 2) % 4 + 2) * 230.0 + 25.0) * ((id + 3) % 4);
	tab[id] = color;
}

__kernel	void	ship(__global float4 *v,
						 __global char *tab,
						 __global float2 *c)
{
	int				id;
	float			zoom;
	float			i;
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

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
	tab[id] = (sin(0.016 * i + id % 4 + 2) * 230 + 25) * ((id + 1) % 4);
}
