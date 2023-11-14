/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:05:58 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/14 18:45:08 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void get_x(t_fdf *fdf)
{
	int i;

	i = 0;
	fdf->meta.x = 0;
	while (fdf->meta.buf[i] != '\n')
	{
		if (ft_isdigit(fdf->meta.buf[i]))
		{
			fdf->meta.x++;
			while (fdf->meta.buf[i] != '\n' && ft_isdigit(fdf->meta.buf[i]))
				i++;
		}
		else
			i++;
	}
	ft_printf("SIZE X = %i \n", fdf->meta.x);
}

void get_y(t_fdf *fdf)
{
	int i;

	i = 0;
	fdf->meta.y = 0;
	while (fdf->meta.buf[i])
	{
		if (fdf->meta.buf[i] == '\n')
			fdf->meta.y++;
		i++;
	}
	ft_printf("SIZE Y = %i \n", fdf->meta.y);
}

void free_matrix(t_fdf *fdf, int size)
{
	int ynew = size;
	while (--ynew >= 0)
	{
		if(fdf->meta.mtx[ynew])
		{
			free(fdf->meta.mtx[ynew]);
			fdf->meta.mtx[ynew] = NULL;	
		}
	}
	free(fdf->meta.mtx);
	fdf->meta.mtx = NULL;
}

void	general_free(t_fdf *fdf)
{
	if (fdf->meta.mtx)
	{
		free_matrix(fdf, fdf->meta.y);
		fdf->meta.mtx = NULL;
	}
	if (fdf->meta.buf)
	{
		free(fdf->meta.buf);
		fdf->meta.buf = NULL;
	}
	if (fdf)
	{
		free(fdf);
		fdf = NULL;
	}
	ft_printf("\n ===================== All memory freed ===================== \n");
	exit(EXIT_SUCCESS);
}
