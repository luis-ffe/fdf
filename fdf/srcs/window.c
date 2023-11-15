/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:09:32 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/15 11:17:42 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// supressed error here;
//void put_a(t_fdf *fdf);

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
	ft_printf("KEY PRESS = %x\n", key);
	//comentar
	//put_a(fdf);
	return (0);
}



int	my_pixel_put(t_fdf *fdf)                                      ///////////////////////mega leaks algures aqui
{
	int x;
	int y;

	static int xm;
	static int ym;

	ym = (WIN_H / 2) - (fdf->meta.zoom/2) * fdf->meta.y;
	
	y = 0;
	while(y < fdf->meta.y)
	{
		x = 0;
		xm = (WIN_W / 2) - (fdf->meta.zoom/2) * fdf->meta.x;
		while (x < fdf->meta.x)
		{
			xm += fdf->meta.zoom;
			mlx_pixel_put(fdf->meta.mlx_p, fdf->meta.win_p, xm, ym, 0x00ff00);
			x++;
		}
		ym += fdf->meta.zoom;
		y++;
	}
	return (0);
}

//comentar para encontrar merdas
//fazer destroy image

// void put_a(t_fdf *fdf)
// {
// 	fdf->meta.img = mlx_new_image(fdf->meta.mlx_p, WIN_W, WIN_H);
// 	fdf->meta.addr = mlx_get_data_addr(fdf->meta.img, &fdf->meta.bits_per_pixel, &fdf->meta.line_length, &fdf->meta.endian);
// 	my_pixel_put(fdf);
// 	mlx_put_image_to_window(fdf->meta.mlx_p, fdf->meta.win_p, fdf->meta.img, 0, 0);
// }


void run_window(t_fdf *fdf)
{
	fdf->meta.mlx_p = mlx_init();
	fdf->meta.win_p = mlx_new_window(fdf->meta.mlx_p, WIN_W, WIN_H, "FDF 42");

//comentar
	//my_pixel_put(fdf); //remove if activating puta   check the leaks!!!
	mlx_hook(fdf->meta.win_p, KeyPress, KeyPressMask, &ft_zoom, fdf);
	mlx_hook(fdf->meta.win_p, DestroyNotify, NoEventMask, &close_fdf, fdf);
	mlx_loop_hook(fdf->meta.mlx_p, &my_pixel_put, fdf);
	mlx_loop(fdf->meta.mlx_p);
}
