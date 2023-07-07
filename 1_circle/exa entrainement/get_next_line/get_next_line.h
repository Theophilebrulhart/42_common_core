/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:28:54 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/26 09:25:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char    *get_next_line(int fd);
int has_line(char *str);
char    *ft_strndup(char *s, int n);
int ft_strlen(char *str);
char    *ft_strjoin(char *s1, char *s2);

#endif