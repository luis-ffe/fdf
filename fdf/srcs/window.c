/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:00:29 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 16:37:01 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	window_updater(t_info *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, fdf->img_w, fdf->img_h);
	draw_option(fdf);
}

void	run_window(t_info *fdf)
{
	mlx_mouse_hook(fdf->mlx_win, mouse_key, fdf);
	mlx_hook(fdf->mlx_win, KeyPress, KeyPressMask, key_detect, fdf);
	mlx_hook(fdf->mlx_win, DestroyNotify, NoEventMask, close_win_free, fdf);
	mlx_loop(fdf->mlx);
}
