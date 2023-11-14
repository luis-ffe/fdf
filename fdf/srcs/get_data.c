/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:06:01 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/14 20:39:30 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void testprint_array(t_fdf *fdf)
{
	int x = 0;
	int y = 0;

	while (y < fdf->meta.y)
	{
		while (x < fdf->meta.x)
		{
			ft_printf("[%i]", fdf->meta.mtx[y][x]); // Adjust the format as needed
			x++;
		}
		x = 0;
		ft_printf("\n");
		y++;
	}
}

void	add_zvalue_matrix(t_fdf *fdf)
{
	int i;
	int j;
	int x;
	int y;
	char *nbr;

	nbr = malloc(sizeof(char) * 13);
	if (!nbr)
		general_free(fdf);
	ft_bzero(nbr, 13);
	i = 0;
	x = 0;
	y = 0;
	while (fdf->meta.buf[i])
	{
		j = 0;
		if (ft_isdigit(fdf->meta.buf[i]))
		{
			if (x >= fdf->meta.x)
			{
				free(nbr);
				general_free(fdf);  //////////////////////////////////
			}
			while(ft_isdigit(fdf->meta.buf[i + j]))
			{
				nbr[j] = fdf->meta.buf[i + j];
				j++;
			}
			fdf->meta.mtx[y][x] = ft_atoi(nbr);
			i += (j - 1);
			x++;
		}
		if (fdf->meta.buf[i] == '\n')
		{
			y++;
			if (x != fdf->meta.x)
			{
				free(nbr);
				general_free(fdf);  //////////////////////////////////
			}
			x = 0;
		}
		i++;
	}
	free(nbr);
}

void	alloc_matrix(t_fdf *fdf)
{
	int ytemp;

	ytemp = 0;
	fdf->meta.mtx = (int **)malloc(sizeof(int *) * fdf->meta.y);
	if (!fdf->meta.mtx)
	{
		general_free(fdf);  //////////////////////////////////
	}
	while (ytemp < fdf->meta.y)
	{
		fdf->meta.mtx[ytemp] = (int *)malloc(sizeof(int) * fdf->meta.x);
		if (!fdf->meta.mtx[ytemp])
		{
			free_matrix(fdf, ytemp);
			general_free(fdf);   //////////////////////////////////
		}
		ytemp++;
	}
}

void set_size_matrix(t_fdf *fdf)
{
	get_x(fdf);
	get_y(fdf);
	alloc_matrix(fdf);
	if (fdf->meta.mtx)
		add_zvalue_matrix(fdf);
}

void map_init(t_fdf *fdf, char *filename)
{
	int	bytesRead;
	
	fdf->meta.fd = open(filename, O_RDONLY);
	if (fdf->meta.fd < 0)
	{
		ft_printf("Error opening file");
		general_free(fdf);        //////////////////////////////////
	}
	fdf->meta.buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!fdf->meta.buf)
	{
		ft_printf("Error allocating buffer");
		general_free(fdf); //////////////////////////////////
	}
	bytesRead = read(fdf->meta.fd, fdf->meta.buf, BUFFER_SIZE);
	if (bytesRead < 0)
	{
		ft_printf("Error reading from file");
		general_free(fdf);
	}
	else
	{
		fdf->meta.buf[bytesRead] = '\0';
		set_size_matrix(fdf);
	}
	testprint_array(fdf);
	close(fdf->meta.fd);
}
