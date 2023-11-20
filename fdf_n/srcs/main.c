/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:52:20 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 15:47:06 by luis-ffe         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	argc_checker(argc);
	fdf = init();
	map_init(fdf, argv[1]);
	run_window(fdf);
	general_free(fdf);
	return (0);
}
