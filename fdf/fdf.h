/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:53:08 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/14 20:44:50 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef fdf_H
# define fdf_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "includes/libft/libft.h"
# include "includes/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

//macros

# define READ_BUFFER 700000
# define WIN_W 800
# define WIN_H 800

//structs

//fazer um array a apontar x y para esta estrutura. allocar e colocar.

typedef struct	s_coord
{
	float x;
	float y;
	float z;
}				t_coord;


typedef struct	s_meta
{
	void 	*mlx_p;
	void	*win_p;
	int		**mtx;
	char	*buf;
	int		fd;
	int 	x;
	int 	y;
}				t_meta;

//main structure to initialize all the others

typedef struct	s_fdf
{
	t_meta	meta;
}				t_fdf;

//init

t_fdf	*init(void);

//utilis_data.c
void	get_x(t_fdf *fdf);
void	get_y(t_fdf *fdf);
void	free_matrix(t_fdf *fdf, int size);
void	general_free(t_fdf *fdf);

//get_data.c
void	testprint_array(t_fdf *fdf); //test function to be removed
void	add_zvalue_matrix(t_fdf *fdf); // necessario reduzir esta funnction ao maximo.
void	alloc_matrix(t_fdf *fdf);
void	set_size_matrix(t_fdf *fdf);
void	map_init(t_fdf *fdf, char *filename);

void	run_window(t_fdf *fdf);

#endif
