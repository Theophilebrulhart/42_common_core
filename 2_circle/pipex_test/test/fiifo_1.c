/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fiifo_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:47:54 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/29 11:23:12 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		str[] = {1, 2, 3, 4, 5, 6};
	int		i;

	fd = open("fifo1", O_WRONLY);
	if (fd == -1)
		return (1);
	i = 0;
	while (str[i])
	{
		if (write(fd, str + i, sizeof(*str)) == -1)
			return (1);
		printf("wrote : %d\n", str[i]);
		i++;
	}
	close(fd);
	printf("everything alright\n");
	return (0);
}
