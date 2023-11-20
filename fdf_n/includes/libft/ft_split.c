/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:15 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/20 18:16:18 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_count(char const *s1, char c)
{
	int			count;
	const char	*s;

	s = s1;
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

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**split;

	if (!s || !c)
		return(NULL);
	split = (char **)malloc(sizeof(char *) * (my_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			if (!ft_strchr(s, c))
				j = ft_strlen(s);
			else
				j = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, j);
			s += j;
		}
		while (*s && *s == c)
			s++;
	}
	split[i] = NULL;
	return (split);
}
