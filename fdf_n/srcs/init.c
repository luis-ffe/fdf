/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:03 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 18:54:42 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void init_img(t_fdf fdf)
// {
// 	fdf->	
// } cenas da imagem e window ainda por fazer

void	init_values(t_fdf *fdf)
{
	// fdf->meta.map = NULL;
	fdf->meta.mlx_p = NULL;
	fdf->meta.win_p = NULL;
	fdf->meta.mtx = NULL;
	fdf->meta.buf = NULL;
	fdf->meta.x = 0;
	fdf->meta.y = 0;
	fdf->meta.x_in = 0;
	fdf->meta.y_in = 0;
	fdf->meta.fd = 0;
	fdf->meta.zoom = 30;
	fdf->meta.map = NULL;
// 	fdf->meta.img = NULL;
// 	fdf->meta.addr = NULL;
// 	fdf->meta.bits_per_pixel = 32;
// 	fdf->meta.line_length = 32;
// 	fdf->meta.endian = 0;
}

t_fdf	*init(void)
{
	t_fdf *fdf;
	
	fdf = malloc(sizeof(t_fdf));
	if(!fdf)
		return (NULL);
	init_values(fdf);
	//init_img();
	return (fdf);
}

/*               TESTER         printz [x, y, z]  */

void	testprint_array(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->meta.y)
	{
		while (x < fdf->meta.x)
		{
			ft_printf("[%i,", fdf->meta.map[y][x].x);
			ft_printf(" %i,", fdf->meta.map[y][x].y);
			ft_printf(" %i]", fdf->meta.map[y][x].z);
			x++;
		}
		x = 0;
		ft_printf("\n");
		y++;
	}
}

/*
//to print jus zzz

void	testprint_array(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < fdf->meta.y)
	{
		while (x < fdf->meta.x)
		{
			ft_printf("[%i]", fdf->meta.mtx[y][x]);
			x++;
		}
		x = 0;
		ft_printf("\n");
		y++;
	}
}
*/