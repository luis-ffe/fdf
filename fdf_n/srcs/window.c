/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:09:32 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 19:24:26 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void zoom_update(t_fdf *fdf);

int	close_fdf(t_fdf *fdf)
{
	mlx_destroy_window(fdf->meta.mlx_p, fdf->meta.win_p);
	mlx_destroy_display(fdf->meta.mlx_p);                                         ///////////////////////mega leaks algures aqui
	free(fdf->meta.mlx_p);
	general_free(fdf);
	ft_printf("CLOSE WINDOW\n");
	exit(0);
}

int	ft_zoom(int key, t_fdf *fdf)
{
	if(key == XK_KP_Add)
		fdf->meta.zoom++;
	if(key == XK_KP_Subtract && fdf->meta.zoom > 1)
		fdf->meta.zoom--;
	if (key == XK_Escape)
	close_fdf(fdf);
	ft_printf("KEY PRESS = %x\n", key);
	ft_printf("KEY PRESS = %i\n", fdf->meta.zoom);
	return (0);
}

//usar esta faze arrays para a represntation e math.

int	my_pixel_put(t_fdf *fdf)
{
	int x;
	int y;
	
	pixels_info(fdf);
	y = 0;
	while(y < fdf->meta.y)
	{
		x = 0;
		while (x < fdf->meta.x)
		{
			mlx_pixel_put(fdf->meta.mlx_p, fdf->meta.win_p, fdf->meta.map[y][x].x, fdf->meta.map[y][x].y, 0x00ff00);
			x++;
		}
		y++;
	}
	return (0);
}

// adicionar update dos novos pontos.

void run_window(t_fdf *fdf)
{
	fdf->meta.mlx_p = mlx_init();
	fdf->meta.win_p = mlx_new_window(fdf->meta.mlx_p, WIN_W, WIN_H, "FDF 42");
	
	my_pixel_put(fdf);
	mlx_hook(fdf->meta.win_p, KeyPress, KeyPressMask, &ft_zoom, fdf);
	mlx_hook(fdf->meta.win_p, DestroyNotify, NoEventMask, &close_fdf, fdf);
	mlx_loop_hook(fdf->meta.mlx_p, &my_pixel_put, fdf);
	mlx_loop(fdf->meta.mlx_p);
}
