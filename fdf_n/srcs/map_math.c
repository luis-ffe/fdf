/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:55:27 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 19:25:56 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	pixel_spacer(t_fdf *fdf)
{
	static int	x;
	static int	y;

	while (y < fdf->meta.y)
	{
		while (x < fdf->meta.x)
		{
			fdf->meta.map[y][x].x = x * fdf->meta.zoom;
			fdf->meta.map[y][x].y = y * fdf->meta.zoom;
			//fdf->meta.map[y][x].z = z * fdf->meta.zoom;
			x++;
		}
		x = 0;
		y++;
	}
}

void	pixel_center(t_fdf *fdf)
{
	static int	x;
	static int	y;
	int y_start;
	int x_start;
	
	y_start = (WIN_H / 2) - (fdf->meta.y * fdf->meta.zoom) / 2;
	x_start = (WIN_W / 2) - (fdf->meta.x * fdf->meta.zoom) / 2;
	while (y < fdf->meta.y)
	{
		while (x < fdf->meta.x)
		{
			fdf->meta.map[y][x].x += x_start;  // pode estar aqui o erro se nao fizer esta dependente da anterior 
			fdf->meta.map[y][x].y += y_start;
			//fdf->meta.map[y][x].z = z * fdf->meta.zoom;
			x++;
		}
		x = 0;
		y++;
	}
}


void	pixels_info(t_fdf *fdf)
{
	pixel_spacer(fdf);
	pixel_center(fdf);
}