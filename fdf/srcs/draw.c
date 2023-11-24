/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:27:06 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 19:03:02 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_line_2d(t_info *fdf, t_pix pi, t_pix pf)
{
	if (pi.x < fdf->map_w - 1)
	{
		pf.x = pi.x + 1;
		pf.y = pi.y;
		bresenham_2d(fdf, pi, pf);
	}
	if (pi.y < fdf->map_h - 1)
	{
		pf.x = pi.x;
		pf.y = pi.y + 1;
		bresenham_2d(fdf, pi, pf);
	}
}

void	draw_plane_2d(t_info *fdf)
{
	t_pix	pi;
	t_pix	pf;

	pi.y = 0;
	pf.x = 0;
	pf.y = 0;
	while (pi.y < fdf->map_h)
	{
		pi.x = 0;
		while (pi.x < fdf->map_w)
		{
			draw_line_2d(fdf, pi, pf);
			pi.x++;
		}
		pi.y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}

static void	draw_line(t_info *fdf, t_pix pi, t_pix pf)
{
	if ((pi.x < fdf->map_w - 1) && (pi.y < fdf->map_h))
	{
		pf.x = pi.x + 1;
		pf.y = pi.y;
		bresenham_3d(fdf, pi, pf);
	}
	if ((pi.y < fdf->map_h - 1) && (pi.x < fdf->map_w))
	{
		pf.x = pi.x;
		pf.y = pi.y + 1;
		bresenham_3d(fdf, pi, pf);
	}
}

void	final_draw(t_info *fdf)
{
	t_pix	pi;
	t_pix	pf;

	pi.y = 0;
	pf.x = 0;
	pf.y = 0;
	while (pi.y < fdf->map_h)
	{
		pi.x = 0;
		while (pi.x < fdf->map_w)
		{
			draw_line(fdf, pi, pf);
			pi.x++;
		}
		pi.y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_win, fdf->img, 0, 0);
}
