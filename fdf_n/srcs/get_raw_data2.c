/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:48:52 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 18:52:31 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/* set matrix with pixel values x y and z for math operations */

void	raw_to_pixels(t_fdf *fdf)
{
	int	x;
	int	y;
	
	y = 0;
	while(y < fdf->meta.y)
	{
		x = 0;
		while (x < fdf->meta.x)
		{
			fdf->meta.map[y][x].x = x;
			fdf->meta.map[y][x].y = y;
			fdf->meta.map[y][x].z = fdf->meta.mtx[y][x];
			x++;
		}
		y++;
	}
}

/* gets the sizes to proceed with matrix memoory allocation */

void	set_size_matrix(t_fdf *fdf)
{
	get_x(fdf);
	get_y(fdf);
	alloc_matrix(fdf);
	if (fdf->meta.mtx)
	{
		add_zvalue_matrix(fdf);
		alloc_pixels(fdf);
		raw_to_pixels(fdf);
	}
}
