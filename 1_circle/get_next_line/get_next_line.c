/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:42:58 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/01/03 14:26:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_size(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*separation(char *buffer, char **str)
{
	char	*dup_buf;

	dup_buf = buffer;
	*str = ft_strcat(*str, ft_substr(buffer, 0, (find_size(buffer) + 1)));
	if (!*str[0])
	{
		free(*str);
		*str = NULL;
	}
	buffer = ft_substr(buffer, (find_size(buffer) + 1), ft_strlen(buffer));
	free(dup_buf);
	return (buffer);
}

size_t	lign_check(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

char	*reading(char *buffer, char **str, int fd)
{
	int			nbr_byt;

	nbr_byt = 1;
	while (lign_check(*str) == 0 && nbr_byt > 0)
	{
		nbr_byt = read(fd, buffer, BUFFER_SIZE);
		buffer[nbr_byt] = '\0';
		buffer = separation(buffer, str);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;

	str = NULL;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (buffer)
	{
		buffer = separation(buffer, &str);
		if (lign_check(str))
			return (str);
		free(buffer);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (0);
	buffer = reading(buffer, &str, fd);
	if (str == NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	return (str);
}

// int    main(void)
// {
//     char    *line;
//     int        i;
//     int        fd2;

//     fd2 = open("test2.txt", O_RDONLY);
//     i = 1;
//     //line = get_next_line(fd2);
//     //char *c;
//     //read(fd2, c, BUFFER_SIZE);
//     //printf("VALUE STR : %s\n", c);
//     while (i <= 10)
//     {
//         line = get_next_line(fd2);
//         if (line == NULL)
//             printf("\nline [%02d]: %s", i, line);
//         else
//             printf("line [%02d]: %s", i, line);
//         free(line);
//         i++;
//     }
//     close(fd2);
//     return (0);
// }
