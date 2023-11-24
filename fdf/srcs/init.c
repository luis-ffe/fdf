/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:43:34 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 18:34:25 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	general_free(t_info *fdf)
{
	int	k;

	k = 0;
	while (k < fdf->map_h)
	{
		free(fdf->map[k]);
		k++;
	}
	free(fdf->map);
	free(fdf);
	ft_printf("\n -- TRUE -- \n");
}

int	close_win_free(t_info *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->mlx_win);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	ft_printf("\n-- Display Cleared --\n");
	general_free(fdf);
	exit(EXIT_SUCCESS);
}

t_info	*init_alloc(void)
{
	t_info	*fdf;

	fdf = malloc(sizeof(t_info));
	if (!fdf)
		exit(EXIT_SUCCESS);
	return (fdf);
}

void	init_fields(t_info *fdf)
{
	fdf->mlx = mlx_init();
	fdf->mlx_win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FdF");
	fdf->img_w = 1920;
	fdf->img_h = 1080;
	fdf->img = mlx_new_image(fdf->mlx, fdf->img_w, fdf->img_h);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel,
			&fdf->line_length, &fdf->endian);
	fdf->map_h = 0;
	fdf->map_w = 0;
	fdf->map = NULL;
	fdf->ops.zoom = 20;
	fdf->ops.x_start = 0;
	fdf->ops.y_start = 0;
	fdf->ops.x_ag = 0.61;
	fdf->ops.y_ag = 0;
	fdf->ops.z_ag = 0;
	fdf->color = 0xFFFFFF;
	fdf->plane = 1;
}
