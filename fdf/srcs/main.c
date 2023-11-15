/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:52:20 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/15 10:37:32 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	argc_checker(int argc)
{
    if (argc != 2)
    {
        ft_printf("Correct use: ./fdf <map_file.fdf> \n");
        exit(EXIT_SUCCESS);
    }	
}


/*
all the points where there can be errors and exit the program
should free all the memory 
*/

int main(int argc, char **argv)
{
	t_fdf *fdf;

	argc_checker(argc);
	fdf = init();
    map_init(fdf, argv[1]);
	ft_printf("%im**********\n", fdf->meta.y);
	ft_printf("%i*m*********\n", fdf->meta.x);
	run_window(fdf); //leaks aqui
	
	//FUNTION fOR THE MATH PROJECTION AND FUTURE ROTATIONS
	//FUNTIONS FOR THE WINDOWS SETUP, UPDATE AND IMAGE BUILD
	//FUNCTION FOR CONTROLS AND MENU
	
	general_free(fdf);
	return 0;
}
