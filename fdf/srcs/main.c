/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:26:40 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 18:20:08 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	check_user_input(int ac, char *s)
{
	if (ac != 2 || open(s, O_RDONLY, 0) < 0)
	{
		ft_printf("Correct use: ./fdf <filename.fdf>\n");
		exit(EXIT_SUCCESS);
	}
}

static void	set_point_spacing(t_info *fdf)
{
	fit_img_in_window(fdf);
	fdf->ops.x_start = (fdf->img_w - (fdf->ops.zoom * fdf->map_w)) / 2;
	fdf->ops.y_start = (fdf->img_h - (fdf->ops.zoom * fdf->map_h)) / 2;
}

int	main(int argc, char **argv)
{
	t_info	*fdf;

	check_user_input(argc, argv[1]);
	fdf = init_alloc();
	init_fields(fdf);
	read_file(&fdf, argv[1]);
	set_point_spacing(fdf);
	final_draw(fdf);
	run_window(fdf);
}
