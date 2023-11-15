/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:09:32 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/14 20:50:57 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


int pipi(void)
{
	return (15);
}

int	close_fdf(t_fdf *fdf)
{
	mlx_destroy_window(fdf->meta.mlx_p, fdf->meta.win_p);
	mlx_destroy_display(fdf->meta.mlx_p);
	free(fdf->meta.mlx_p);
	general_free(fdf);
	ft_printf("CLOSE WINDOW\n");
	return (0);
}

void	my_pixel_put(t_fdf *fdf)
{
	int x;
	int y;

	static int xm;
	static int ym;

	y = 0;
	while(y < fdf->meta.y)
	{
		x = 0;
		xm = 0;
		while (x < fdf->meta.x)
		{
			xm += pipi();
			mlx_pixel_put(fdf->meta.mlx_p, fdf->meta.win_p, xm, ym, 0xffffff);
			x++;
		}
		ym += pipi();
		y++;
	}	
}

void run_window(t_fdf *fdf)
{
	fdf->meta.mlx_p = mlx_init();
	fdf->meta.win_p = mlx_new_window(fdf->meta.mlx_p, WIN_H, WIN_H, \
		"FDF 42");
		
	//fdf->meta.p_img = mlx_new_image(fdf->meta.mlx_p, WIN_W, WIN_H);
	
	my_pixel_put(fdf);
	//mlx_pixel_put(fdf->meta.mlx_p, fdf->meta.win_p, 40, 40, 0xffffff);
	
	//mlx_put_image_to_window(fdf->meta.mlx_p, fdf->meta.win_p, \
	//	fdf->meta.p_img, 0, 0);

	mlx_hook(fdf->meta.win_p, DestroyNotify, NoEventMask, &close_fdf, fdf);
	mlx_loop(fdf->meta.mlx_p);
}



/*
abre o terminal
corre o vlagrind 
verifca se tudo esta em ordem

proximo passo :

fazer estruturas para colocar os dados x y z e cor 
fazer estrutura para colocar pointers para as functions para desenhar a imagem
criar a imagem antes de a colocar na janela
fazer isso em loop.
*/