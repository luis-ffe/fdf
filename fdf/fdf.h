/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:53:08 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/27 10:33:08 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "includes/libft/libft.h"
# include "includes/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WIN_W 1920
# define WIN_H 1080

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_pix
{
	float	x;
	float	y;
}			t_pix;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
}			t_point;

typedef struct s_math
{
	int		zoom;
	int		x_start;
	int		y_start;
	float	x_ag;
	float	y_ag;
	float	z_ag;
}			t_math;

typedef struct s_info
{
	float	zup;
	int		map_w;
	int		map_h;
	int		**map;
	void	*mlx;
	void	*mlx_win;
	int		img_w;
	int		img_h;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_math	ops;
	int		color;
	int		plane;
}			t_info;

//		init.c
void		general_free(t_info *fdf);
int			close_win_free(t_info *fdf);
t_info		*init_alloc(void);
void		init_fields(t_info *fdf);

//		get_data.c
void		read_file(t_info **fdf, char *s);
int			set_h(char *s);
int			set_w(char *s);
void		fill_array_row(int *row, char *s, t_info *fdf);

//		utils.c
int			ft_countwords(char const *s, char c);
int			ft_nbr_len(long n);
int			ft_max(int x, int y);
void		get_error(t_info **fdf);

//		window.c
void		window_updater(t_info *fdf);
void		run_window(t_info *fdf);

//		keys.c
int			key_detect(int key, t_info *img);

//		keys_2.c
int			mouse_key(int key, int x, int y, void *param);

//		draw.c
float		point_z_updater(float z, t_info *fdf); /////////////////
void		final_draw(t_info *fdf);
void		draw_plane_2d(t_info *fdf);

//		draw_utilis.c
int			is_valid(t_info *fdf, int x, int y);
void		draw_option(t_info *fdf);
void		get_color(t_info *fdf, int zi, int zf);

//		img_pixel.c
void		my_mlx_pixel_put(t_info *fdf, int x, int y, int color);
void		fit_img_in_window(t_info *fdf);

//		bresenham_algo.c
void		pos_math_2d(t_info *fdf, float *x, float *y, int *z);
void		bresenham_2d(t_info *fdf, t_pix pi, t_pix pf);
void		bresenham_3d(t_info *fdf, t_pix pi, t_pix pf);

#endif

/*
these functions detect the user inputed key and and will
determine wich function to run acording to the conditional statements
TAB = sets the viw from top in a loop.
o, i, k, l, n, m = rotates image on x, y and z axis assuming the first pixel
printed as the starting point of all the axis.
Arrows move the image horizontally or vertically
*/
