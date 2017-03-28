__kernel	void	mandel(__global float4 *v,
						   __global uchar3 *tab,
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
	y = id / 1024;
	x = id % 1024;
	zoom_x = 1024 / v[id].z;
	zoom_y = 1024 / v[id].z;
	c_r = x / zoom_x + v[id].x;
	c_i = y / zoom_y + v[id].y;
	z_r = 0;
	z_i = 0;
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
	tab[id].x = sin(0.016 * (double)i + 4) * 230 + 25;
	tab[id].y = sin(0.013 * (double)i + 2) * 230 + 25;
	tab[id].z = sin(0.01 * (double)i + 1) * 230 + 25;
}

__kernel	void	julia(__global float4 *v,
						  __global uchar3 *tab,
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
	y = id / 1024;
	x = id % 1024;
	zoom_x = 1024 / v[id].z;
	zoom_y = 1024 / v[id].z;
	c_r = c[id].x;
	c_i = c[id].y;
	z_r = x / zoom_x + v[id].x;
	z_i = y / zoom_y + v[id].y;
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
	tab[id].x = sin(0.013 * (double)i + 2) * 230 + 25;
	tab[id].y = sin(0.016 * (double)i + 4) * 230 + 25;
	tab[id].z = sin(0.01 * (double)i + 1) * 230 + 25;
}
