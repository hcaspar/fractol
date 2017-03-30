#define		MAX_X 1024
#define		MAX_Y 1024

__kernel	void	mandel(__global float4 *v,
						   __global char *tab,
						   __global float2 *c)
{
	int				id;
	float			zoom_x;
	float			zoom_y;
	float			i;
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	id = get_global_id(0);
	y = (id / 4) / MAX_Y;
	x = (id / 4) % MAX_X;
	zoom_x = MAX_X / v[id / 4].z;
	zoom_y = MAX_Y / v[id / 4].z;
	c_r = x / zoom_x + v[id / 4].x;
	c_i = y / zoom_y + v[id / 4].y;
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
						  __global char *tab,
						  __global float2 *c)
{
	int				id;
	float			zoom_x;
	float			zoom_y;
	float			i;
	int				x;
	int				y;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	id = get_global_id(0);
	y = (id / 4) / MAX_Y;
	x = (id / 4) % MAX_X;
	zoom_x = MAX_X / v[id / 4].z;
	zoom_y = MAX_Y / v[id / 4].z;
	c_r = c[id / 4].x;
	c_i = c[id / 4].y;
	z_r = x / zoom_x + v[id / 4].x;
	z_i = y / zoom_y + v[id / 4].y;
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
