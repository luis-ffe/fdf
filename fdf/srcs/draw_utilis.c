/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utilis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:48:51 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/23 16:34:44 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_color(t_info *fdf, int zi, int zf)
{
	if ((zi > 0 || zf > 0) && (zi < 20 || zf < 20)) 
		fdf->color = 0x00ff00;
	else if (zi > 19 || zf > 19) 
		fdf->color = 0xfa00fa;
	else if (zi == 0 && zf == 0)
		fdf->color = 0xffffff;
	else if (zi < 0 || zf < 0)
		fdf->color = 0xff0000;
}

int	is_valid(t_info *fdf, int x, int y)
{
	if (fdf->img_w - 1 < x || x < 0)
		return (0);
	if (fdf->img_h - 1 < y || y < 0)
		return (0);
	return (1);
}

void	draw_option(t_info *fdf)
{
	if (fdf->plane == 1)
		final_draw(fdf);
	else if (fdf->plane == -1)
		draw_plane_2d(fdf);
}
