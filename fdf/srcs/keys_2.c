/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 06:55:12 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 14:30:19 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom_in(t_info *fdf)
{
	if (fdf->ops.zoom > 2)
		fdf->ops.zoom /= 1.5;
}

void	zoom_out(t_info *fdf)
{
	if (fdf->ops.zoom < 10000)
		fdf->ops.zoom *= 1.5;
}

int	mouse_key(int key, int x, int y, void *param)
{
	t_info	*fdf;

	(void) x;
	(void) y;
	fdf = (t_info *)param;
	if (key == 5)
		zoom_in(fdf);
	if (key == 4)
		zoom_out(fdf);
	window_updater(fdf);
	return (0);
}
