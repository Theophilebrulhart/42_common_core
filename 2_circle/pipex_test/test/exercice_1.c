/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercice_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/29 14:43:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd[2];
	int	id;
	int array[5];
	int	sum;
	int	i;

	if (pipe(fd))
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	sum = 0;
	i = 0;
	if (id == 0)
	{
		close(fd[0]);
		while (i < 5)
		{
			array[i] = i + 1;
			printf("array : %d, ", array[i]);
			i++;
		}
		if (write(fd[1], array, sizeof(array) * 5) == -1)
			return (1);
		printf("child finish\n");
		close(fd[1]);
	}
	else 
	{
		close(fd[1]);
		wait(NULL);
		if (read(fd[0], array, sizeof(array) * 5) == -1)
			return (0);
		while (i < 5)
		{
			sum += array[i];
			i++;
		}
		printf("sum : %d\n", sum);
		close(fd[0]);
	}
}
	