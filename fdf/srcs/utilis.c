/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:26:18 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/24 19:03:26 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0' && (*(s + i) != '\n'))
	{
		while (*(s + i) == c && *(s + i) != '\0' && (*(s + i) != '\n'))
			i++;
		if ((*(s + i) != '\0') && (*(s + i) != '\n') && (*(s + i) != '\n'))
		{
			count++;
			i++;
		}
		while (*(s + i) != c && *(s + i) != '\0' && (*(s + i) != '\n'))
			i++;
	}
	return (count);
}

int	ft_nbr_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	module(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	get_error(t_info **fdf)
{
	ft_printf("Error Detected...\nMemory status:\n Must say 'TRUE':");
	general_free(*fdf);
	exit(EXIT_SUCCESS);
}
