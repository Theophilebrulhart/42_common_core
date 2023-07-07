/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:14:05 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/29 11:23:54 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	i;
	int	str[6];

	fd = open("fifo1", O_RDONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (str[i])
	{
		if (read(fd, str + i, sizeof(*str)) == -1)
			return (1);
		printf("received : %d\n", str[i]);
		i++;
	}
	close(fd);
	return (0);
}
