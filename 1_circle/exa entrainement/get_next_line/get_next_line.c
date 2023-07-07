/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:28:20 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/26 09:55:38 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char **str)
{
    char    *dst;
    char    *tmp;
    int     i;

    if (!*str)
        return (NULL);
    i = 0;
    while ((*str)[i] && (*str)[i] != '\n')
        i++;
    if ((*str)[i] == '\n')
        i++;
    if (!(*str)[i])
        tmp = NULL;
    else
        tmp = ft_strndup(*str + i, ft_strlen(*str + i));
    dst = ft_strndup(*str, i);
    free(*str);
    *str = tmp;
    return (dst);
}

char    *get_next_line(int fd)
{
    static char *left_s;
    char        buffer[BUFFER_SIZE + 1];
    int         n_byte;

    if (fd < 0 || read(fd, buffer, 0) < 0 || fd > 4095 || BUFFER_SIZE <= 0)
        return (0);
    if (left_s && has_line(left_s))
        return (get_line(&left_s));
    n_byte = read(fd, buffer, BUFFER_SIZE);
    buffer[n_byte] = 0;
    while (0 < n_byte && n_byte <= BUFFER_SIZE)
	{
		left_s = ft_strjoin(left_s, buffer);
		if (!left_s || has_line(left_s))
			break ;
		n_byte = read(fd, buffer, BUFFER_SIZE);
		buffer[n_byte] = 0;
	}
    return(get_line(&left_s));
}
