/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecting_standard_output.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:11:10 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/02 15:24:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	fd2;
	int	id;

	id = fork();
	fd = 0;
	fd2 = 0;
	if (id == -1)
		return (0);
	if (id == 0)
	{
		printf("We are in the chlid process\n");
		fd = open("redirectoring.txt", O_WRONLY | O_CREAT, 0777);
		if (fd == -1)
			return (1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		printf("\n\n now we write in the file\n\n\n");
		execlp("ping", "ping", "-c", "1", "google.com", NULL);
	}
	else
	{
		printf("we are in th parent\n");
	}
	return (0);
}
