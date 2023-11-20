/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:05:58 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 18:28:45 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*this function counts the total number of z values in the file line 
giving the X value to be used*/

void	get_x(t_fdf *fdf)
{
	int	i;

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

/*counts total number of newline chars giving the total y value*/

void	get_y(t_fdf *fdf)
{
	int	i;

	i = 0;
	fdf->meta.y = 0;
	printf("%s\n", fdf->meta.buf);
	while (fdf->meta.buf[i])
	{
		if (fdf->meta.buf[i] == '\n')
			fdf->meta.y++;
		i++;
	}
	ft_printf("SIZE Y = %i \n", fdf->meta.y);
}

/* 1st matrix free function*/
void	free_matrix(t_fdf *fdf, int size)
{
	int	ynew;

	ynew = size;
	while (--ynew >= 0)
	{
		if (fdf->meta.mtx[ynew])
		{
			free(fdf->meta.mtx[ynew]);
			fdf->meta.mtx[ynew] = NULL;
		}
	}
	free(fdf->meta.mtx);
	fdf->meta.mtx = NULL;
}

/* general free function */

void	general_free(t_fdf *fdf)
{
	if (fdf->meta.mtx)
	{
		free_matrix(fdf, fdf->meta.y);
		fdf->meta.mtx = NULL;
	}
	if(fdf->meta.map)
		free_map(fdf, fdf->meta.y);
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
	ft_printf("\n = CLOSING = \n");
	exit(EXIT_SUCCESS);
}

void split_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	free_map(t_fdf *fdf, int size)
{
	int	ynew;

	ynew = size;
	while (--ynew >= 0)
	{
		if (fdf->meta.map[ynew])
		{
			free(fdf->meta.map[ynew]);
			fdf->meta.map[ynew] = NULL;
		}
	}
	free(fdf->meta.map);
	fdf->meta.mtx = NULL;
}