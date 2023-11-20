/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:53:08 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 19:24:46 by luis-ffe         ###   ########.fr       */
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
# define READ_BUFFER 7000000
# define WIN_W 1920
# define WIN_H 1080

//structs

//fazer um array a apontar x y para esta estrutura. allocar e colocar.

typedef struct	s_coord
{
	int x;  
	int y;
	int z;
}				t_coord;

typedef struct	s_meta
{
	t_coord **map;
	void 	*mlx_p;
	void	*win_p;
	int		**mtx;
	char	*buf;
	int		fd;
	int 	x;  //total x elements count 0 to last
	int 	y;  // total lines
	int x_in;  // centered x start
	int y_in; //centered y start value
	int	zoom;
	// void	*img;
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
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
void	split_free(char **s);
void	free_map(t_fdf *fdf, int size);

//get_data.c
void	testprint_array(t_fdf *fdf); //test function to be removed
void	add_zvalue_matrix(t_fdf *fdf); // necessario reduzir esta funnction ao maximo.
void	alloc_matrix(t_fdf *fdf);
void	alloc_pixels(t_fdf *fdf);
void	set_size_matrix(t_fdf *fdf);
void	map_init(t_fdf *fdf, char *filename);
void	raw_to_pixels(t_fdf *fdf);

//map_math.c
void	pixel_center(t_fdf *fdf);
void	pixel_spacer(t_fdf *fdf);
void	pixels_info(t_fdf *fdf);


void	run_window(t_fdf *fdf);

#endif
