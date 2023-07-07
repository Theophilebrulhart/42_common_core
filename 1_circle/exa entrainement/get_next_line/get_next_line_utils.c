/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:33:13 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/26 09:37:46 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_line(char *s)
{
	if (!s)
		return (0);
	while (*s++)
		if (*s == '\n')
			return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l++;
	return (l);
}

char    *ft_strndup(char *s, int n)
{
    char *str;
    int i;

    str = malloc((n + 1) * sizeof(*str));
    if (!str)
        return (0);
    i = 0;
    if (s)
    {
        while (i < n)
        {
            str[i] = s[i];
            i++;
        }
    }
    str[i] = 0;
    return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	char	*s;
	size_t	i;
	size_t	l;

	s = s1;
	l = ft_strlen(s1);
	if (ft_strlen(s2))
		l += ft_strlen(s2);
	dst = malloc(l + 1);
	if (!dst)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			dst[i++] = *(s1++);
	if (s2)
		while (*s2)
			dst[i++] = *(s2++);
	dst[i] = 0;
	free(s);
	return (dst);
}
