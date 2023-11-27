/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:26:50 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/27 10:33:10 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	point_z_updater(float z, t_info *fdf)
{
	if (fdf->zup < 0)
		z /= fdf->zup;
	if (fdf->zup > 0)
		z *= fdf->zup;
	return (z);
}

void	z_react_key(int key, t_info *fdf)
{
	if (key == XK_1)
		fdf->zup += 1;
	if (key == XK_0)
		fdf->zup -= 1;
}

static void	map_move(int key, t_info *fdf)
{
	if (key == XK_Up)
		fdf->ops.y_start -= 10;
	else if (key == XK_Down)
		fdf->ops.y_start += 10;
	else if (key == XK_Right)
		fdf->ops.x_start += 10;
	else
		fdf->ops.x_start -= 10;
}

static void	map_rotate(int key, t_info *fdf)
{
	if (key == XK_i)
		fdf->ops.x_ag += 0.2;
	else if (key == XK_o)
		fdf->ops.x_ag -= 0.2;
	else if (key == XK_k)
		fdf->ops.y_ag += 0.2;
	else if (key == XK_l)
		fdf->ops.y_ag -= 0.2;
	else if (key == XK_n)
		fdf->ops.z_ag += 0.2;
	else if (key == XK_m)
		fdf->ops.z_ag -= 0.2;
}

int	key_detect(int key, t_info *fdf)
{
	ft_printf("key %x \n", key);
	if (key == XK_Escape)
		close_win_free(fdf);
	else if (key == XK_Up || key == XK_Down
		|| key == XK_Right || key == XK_Left)
		map_move(key, fdf);
	else if (key == XK_Tab)
		fdf->plane *= -1;
	else if (key == XK_i || key == XK_o
		|| key == XK_k || key == XK_l || key == XK_n || key == XK_m)
		map_rotate(key, fdf);
	else if (key == XK_1 || key == XK_0)
		z_react_key(key, fdf);
	else
		return (0);
	window_updater(fdf);
	return (1);
}
