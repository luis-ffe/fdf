/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:22:41 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 19:04:10 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	set_w(char *s)
{
	int		fd;
	int		w;
	int		count;
	char	*l;

	fd = open(s, 'r');
	l = get_next_line(fd);
	w = ft_countwords(l, ' ');
	while (l)
	{
		count = ft_countwords(l, ' ');
		if (w < count)
			w = count;
		free(l);
		l = get_next_line(fd);
	}
	close(fd);
	return (w);
}

int	set_h(char *s)
{
	char	*l;
	int		h;
	int		fd;

	fd = open(s, 'r');
	h = 0;
	l = get_next_line(fd);
	while (l)
	{
		h++;
		free(l);
		l = get_next_line(fd);
	}
	close(fd);
	return (h);
}

int	my_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

void	fill_array_row(int *row, char *s, t_info *fdf)
{
	char	**split;
	int		i;
	int		j;
	int		n;

	n = my_count(s, 32);
	i = 0;
	j = 0;
	split = ft_split(s, 32);
	while (split[j] != NULL && i < n)
	{
		if (i + 1 >= n && n > fdf->map_w)
		{
			free(split[j]);
		}
		else
		{
			row[i++] = ft_atoi(split[j]);
			free(split[j]);
		}
		j++;
	}
	free(split);
}

void	read_file(t_info **fdf, char *file)
{
	char	*l;
	int		fd;
	int		i;
	int		h;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		get_error(fdf);
	(*fdf)->map_h = set_h(file);
	(*fdf)->map_w = set_w(file);
	i = 0;
	h = 0;
	(*fdf)->map = (int **)ft_calloc(sizeof(int *), ((*fdf)->map_h));
	l = get_next_line(fd);
	while (h < (*fdf)->map_h)
		(*fdf)->map[h++] = (int *)ft_calloc(sizeof(int), ((*fdf)->map_w));
	while (l != NULL && i < (*fdf)->map_h)
	{
		fill_array_row((*fdf)->map[i++], l, (*fdf));
		free(l);
		l = get_next_line(fd);
	}
	close(fd);
}
