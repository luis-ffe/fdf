/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:57:52 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/03 16:50:47 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*ft_mem_alloc(size_t nmemb, size_t size);
int		ft_findnl(char *ptr);
size_t	ft_strleng(const char *s);
char	*ft_add_nest(char *nest, char *buffer);
char	*get_next_line(int fd);

#endif
