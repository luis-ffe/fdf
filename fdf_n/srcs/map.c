/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:08:39 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 19:15:52 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_init(t_fdf *fdf, char *filename)
{
	int	bytes_read;

	fdf->meta.fd = open(filename, O_RDONLY);
	if (fdf->meta.fd < 0)
		general_free(fdf);
	fdf->meta.buf = malloc(sizeof(char) * READ_BUFFER);
	if (!fdf->meta.buf)
		general_free(fdf);
	bytes_read = read(fdf->meta.fd, fdf->meta.buf, READ_BUFFER);
	if (bytes_read < 0)
		general_free(fdf);
	else
	{
		fdf->meta.buf[bytes_read] = '\0';
		set_size_matrix(fdf); // in get_raw_data2 and get_raw_data
		pixels_info(fdf);
	}
	testprint_array(fdf);
	close(fdf->meta.fd);
}
