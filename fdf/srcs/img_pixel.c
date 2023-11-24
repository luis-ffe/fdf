/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:15:50 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 14:30:53 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_info *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fit_img_in_window(t_info *fdf)
{
	int	size_x;
	int	size_y;

	size_x = fdf->ops.zoom * fdf->map_w;
	size_y = fdf->ops.zoom * fdf->map_h;
	while (size_x >= fdf->img_w || size_y >= fdf->img_h)
	{
		fdf->ops.zoom /= 2;
		size_x = fdf->ops.zoom * fdf->map_w;
		size_y = fdf->ops.zoom * fdf->map_h;
	}
}
