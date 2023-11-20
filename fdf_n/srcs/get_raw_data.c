/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:06:01 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 18:49:17 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*  writes each x axis number to the correct array line(k)    */

void put_fr_line(int k, t_fdf *fdf, char **s)
{
	int	x;
	int	count;
	
	count = k * (fdf->meta.x - 1);
	x = 0;
	while(x < fdf->meta.x)
	{
		fdf->meta.mtx[k][x] = atoi(s[count + x]);
		x++;
	}
	if(x != fdf->meta.x)
	{
		general_free(fdf);
		split_free(s);
		exit(EXIT_FAILURE);
	}	
}

/*  the same as above but changes the lines to the next one */

void put_z_in(char **s, t_fdf *fdf)
{
	int k;

	k = 0;
	while (k < fdf->meta.y)
	{
		put_fr_line(k, fdf, s);
		k++;
	}
	if(k != fdf->meta.y)
	{	
		general_free(fdf);
		split_free(s);
		exit(EXIT_FAILURE);
	}
}

/* splits the raw input int array of separate strings with the values
 and executes the defenition of z values in the array using the above functions*/

void	add_zvalue_matrix(t_fdf *fdf)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(fdf->meta.buf, ' ');
	put_z_in(split, fdf);
	while(split[i])
		free(split[i++]);
	free(split);
}


/* memory allocation for the current raw matrix */

void	alloc_matrix(t_fdf *fdf)
{
	int	ytemp;

	ytemp = 0;
	fdf->meta.mtx = (int **)malloc(sizeof(int *) * fdf->meta.y);
	if (!fdf->meta.mtx)
	{
		general_free(fdf);
	}
	while (ytemp < fdf->meta.y)
	{
		fdf->meta.mtx[ytemp] = (int *)malloc(sizeof(int) * fdf->meta.x);
		if (!fdf->meta.mtx[ytemp])
		{
			free_matrix(fdf, ytemp);
			general_free(fdf);
		}
		ytemp++;
	}
}



/* memory allocation for the current raw matrix */

void	alloc_pixels(t_fdf *fdf)
{
	int	ytemp;

	ytemp = 0;
	fdf->meta.map = (t_coord **)malloc(sizeof(t_coord *) * fdf->meta.y);
	if (!fdf->meta.map)
	{
		free_map(fdf, ytemp);
		general_free(fdf);
	}
	while (ytemp < fdf->meta.y)
	{
		fdf->meta.map[ytemp] = (t_coord *)malloc(sizeof(t_coord) * fdf->meta.x);
		if (!fdf->meta.map[ytemp])
		{
			free_map(fdf, ytemp);
			general_free(fdf);
		}
		ytemp++;
	}
}

/* Keep going in the raw_data2.c */