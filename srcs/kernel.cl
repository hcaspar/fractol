__kernel	void	draw(__global float4 *v)
{
	float			x;
	float			y;
	float			zoom_x;
	float			zoom_y;
	float			i;
	t_color			color;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			tmp;

	zoom_x = MAX_X / e->v.z;
	zoom_y = MAX_Y / e->v.z;
	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			c_r = x / zoom_x + v.x;
			c_i = y / zoom_y + v.y;
			z_r = 0;
			z_i = 0;
			i = 0;
			tmp = z_r;
			z_r = z_r * z_r - z_i * z_i + c_r;
			z_i = 2 * z_i * tmp + c_i;
			i++;
			while (z_r * z_r + z_i * z_i < 4 && i < v.w)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			color = set_color(i / v.w);
			put_pixel(x, y, color, e);
		}
	}
}
