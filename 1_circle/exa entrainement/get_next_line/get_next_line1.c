/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:43:26 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/10 08:53:16 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static char *get_line(char **s)
{
    char *tmp;
    char *dup;
    int i;

    if (!(*s))
        return (NULL);
    while ((*s)[i] && (*s)[i] != '\n')
        i++;
    if ((*s)[i] == '\n')
        i++;
    if (!(*s[i]))
        tmp = NULL
    else
        tmp = ft_strndup(*s + i, ft_strlen(*s + i));
    dup = ft_strndup(*s, i);
    free(*s);
    *s = tmp;
    return (dup);
}

char    *get_next_line(int fd)
{
    static char *s_left;
    char buffer[BUFFER_SIZE + 1];
    int n;

    if (fd < 0 || read(fd , buffer, 0) < 0 || fd > 4095 || BUFFER_SIZE <= 0)
        return (NULL);
    if (s_left && has_line(s_left))
        return (get_line(&s_left));
    n = read(fd, buffer, BUFFER_SIZE);
    buffer[n] = 0;
    while (n <= BUFFER_SIZE && n > 0)
    {
        s_left = ft_strjoin(s_left, buffer);
        if (!s_left || has_line(s_left))
            break ;
        n = read(fd, buffer, BUFFER_SIZE);
        buffer[n] = 0;
    }
    return (get_line(&s_left));
}