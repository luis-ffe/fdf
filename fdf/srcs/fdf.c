/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:48:14 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/08 14:44:59 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

typedef struct s_coordinate
{
	int	x;
	int	y;
	int	z;
	//int	color[2];
	struct s_coordinate *next;
}	t_coordinate;


t_coordinate	*create_node(int z_val, int y_val, int x_val);
void	filter_data(const char *str, t_coordinate *init_node1);


/*
multithreading ?
cache ?
buffering images before updating the ones in the window?
fastest way to treat data?
matrix
struct
2d map  or 3d already made? 
*/



/*
x (axis) increments with line leng (horizontaly)
y (ordinate) increments every new line (vrticaly)
z (value) stored in the FDF[y][x] position of "matrix"
color = 3*int for R G B
*/
t_coordinate	*create_node(int z_val, int y_val, int x_val)
{
	t_coordinate	*node;
	node = malloc(sizeof(t_coordinate));
	if(!node)
		return (NULL);
	node->x = x_val;
	node->y = y_val;
	node->z = z_val; 
	node->next = NULL;
	return (node);
}

void	lst_add_last(t_coordinate *lst, t_coordinate *new)
{
	while(lst->next)
	{
		lst = lst->next;	
	}
	if(lst->next == NULL)
		lst->next = new;
}


void	filter_data(const char *str, t_coordinate *init_node)
{
	static int nl_count;
	char *nbr;
	int i;
	int j;
	int	x_count;
	
	i = 0;
	x_count = 0;
	nbr = malloc(sizeof(char) * 12);
	while(str[i])
	{
		j = 0;
		if (!ft_isdigit(str[i]))
			break;
		if (str[i] == '\n')
		{
			x_count = 0;
			nl_count++;
			break;
		}
		while(ft_isdigit(str[i + j]))
		{
			nbr[j] = str[i + j];
			j++;
		}
		if(j != 0)
		{
			nbr[j] = '\0';
			i += (j - 1);
			x_count++;
			lst_add_last(init_node, create_node(ft_atoi(nbr), nl_count, x_count));
		}
		i++;
	}
	free(nbr);
}

//newline says x should be reseted

/*

create_node(ft_atoi(nbr), nl_count, x_count);
criar a lista! alocar memoria

*/

// vai ser o cirador de nodes


int main(void)
{
	int fd;
    //void *mlx_ptr;
    //void *win_ptr;
	t_coordinate *point_lst;
	char *buffer_str;
	
	point_lst = NULL;
	buffer_str = malloc(sizeof(char) + 1);
	fd = open("42.fdf", "rb");
	read(fd, buffer_str, READ_BUFFER);

	filter_data(buffer_str, point_lst);
	printf("%s", buffer_str);
	free(buffer_str);
	

    //mlx_ptr = mlx_init();
    //win_ptr = mlx_new_window(mlx_ptr, 900, 900, "CARALHO");
	//mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF);
    //mlx_loop(mlx_ptr);
    return (0);
}
