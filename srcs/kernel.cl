__kernel	void	draw(__global float4 *v,
						 __global float *tab)
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
	y = id / 860;
	x = id % 860;
	zoom_x = 860 / v[id].z;
	zoom_y = 860 / v[id].z;
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
	tab[id] = i / v[id].w;
}
