/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:58:13 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 14:19:21 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	point_math(t_info *fdf, t_point p)
{
	float	xi;
	float	yi;
	float	zi;

	xi = p.x * cos(0.8) - p.y * sin(0.8);
	yi = p.y * cos(0.8) + p.x * sin(0.8);
	p.x = xi * cos(fdf->ops.z_ag) - yi * sin(fdf->ops.z_ag);
	p.y = xi * sin(fdf->ops.z_ag) + yi * cos(fdf->ops.z_ag);
	xi = p.x * cos(fdf->ops.y_ag) + p.z * sin(fdf->ops.y_ag);
	zi = -p.x * sin(fdf->ops.y_ag) + p.z * cos(fdf->ops.y_ag);
	yi = p.y;
	p.y = yi * cos(fdf->ops.x_ag) - zi * sin(fdf->ops.x_ag);
	p.z = yi * sin(fdf->ops.x_ag) + zi * cos(fdf->ops.x_ag);
	p.x = xi;
	p.x += fdf->ops.x_start;
	p.y += fdf->ops.y_start;
	return (p);
}

void	isometric(t_info *fdf, float *x, float *y, int *z)
{
	t_point	point;

	point.x = *x * fdf->ops.zoom;
	point.y = *y * fdf->ops.zoom;
	point.z = *z * fdf->ops.zoom;
	point = point_math(fdf, point);
	*x = point.x;
	*y = point.y;
	*z = point.z;
}

void	pos_math_2d(t_info *fdf, float *x, float *y, int *z)
{
	float	x0;
	float	y0;
	float	z0;

	x0 = *x * fdf->ops.zoom;
	y0 = *y * fdf->ops.zoom;
	z0 = *z * fdf->ops.zoom;
	*x = x0 + fdf->ops.x_start;
	*y = y0 + fdf->ops.y_start;
	*z = z0;
}

void	bresenham_2d(t_info *fdf, t_pix pi, t_pix pf)
{
	float	dx;
	float	dy;
	int		pixel;
	int		z;
	int		z1;

	z = fdf->map[(int)pi.y][(int)pi.x];
	z1 = fdf->map[(int)pf.y][(int)pf.x];
	get_color(fdf, z, z1);
	pos_math_2d(fdf, &pi.x, &pi.y, &z);
	pos_math_2d(fdf, &pf.x, &pf.y, &z1);
	dx = pf.x - pi.x;
	dy = pf.y - pi.y;
	pixel = sqrt((dx * dx) + (dy * dy));
	dx = dx / pixel;
	dy = dy / pixel;
	while (pixel > 0)
	{
		if (is_valid(fdf, pi.x, pi.y))
			my_mlx_pixel_put(fdf, (int)pi.x, (int)pi.y, fdf->color);
		pi.x += dx;
		pi.y += dy;
		pixel--;
	}
}

void	bresenham_3d(t_info *fdf, t_pix pi, t_pix pf)
{
	float	dx;
	float	dy;
	int		pixel;
	int		zi;
	int		zf;

	zi = fdf->map[(int)pi.y][(int)pi.x];
	zf = fdf->map[(int)pf.y][(int)pf.x];
	get_color(fdf, zi, zf);
	isometric(fdf, &pi.x, &pi.y, &zi);
	isometric(fdf, &pf.x, &pf.y, &zf);
	dx = pf.x - pi.x;
	dy = pf.y - pi.y;
	pixel = sqrt((dx * dx) + (dy * dy));
	dx /= pixel;
	dy /= pixel;
	while (pixel)
	{
		if (is_valid(fdf, pi.x, pi.y))
			my_mlx_pixel_put(fdf, (int)pi.x, (int)pi.y, fdf->color);
		pi.x += dx;
		pi.y += dy;
		pixel--;
	}
}
