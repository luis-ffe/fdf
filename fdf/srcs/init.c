/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:27:03 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/15 11:18:19 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// void init_img(t_fdf fdf)
// {
// 	fdf->	
// } cenas da imagem e window ainda por fazer

void	init_values(t_fdf *fdf)
{
	fdf->meta.mlx_p = NULL;
	fdf->meta.win_p = NULL;
	fdf->meta.mtx = NULL;
	fdf->meta.buf = NULL;
	fdf->meta.x = 0;
	fdf->meta.y = 0;
	fdf->meta.fd = 0;
	// fdf->meta.zoom = 15;
	// fdf->meta.img = NULL;
	// fdf->meta.addr = NULL;
	// fdf->meta.bits_per_pixel = 32;
	// fdf->meta.line_length = 32;
	// fdf->meta.endian = 0;
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