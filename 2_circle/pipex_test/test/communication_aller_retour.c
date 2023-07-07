/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communication_aller_retour.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:55:30 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/29 12:13:01 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int	fd_c[2];
	int	fd_p[2];
	int	id;
	int	nbr;

	if (pipe(fd_c) == -1)
		return (1);
	if (pipe(fd_p) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (0);
	if (id == 0)
	{
		close(fd_c[0]);
		close(fd_p[1]);
		if (read(fd_p[0], &nbr, sizeof(nbr)) == -1)
			return (1);
		printf("we read : %d\n", nbr);
		nbr *= 4;
		if (write(fd_c[1], &nbr, sizeof(nbr)) == -1)
		{
			printf("probleme\n");
			return (1);
		}
		printf("we send : %d\n", nbr);
		close(fd_c[1]);
		close(fd_p[0]);
	}
	else
	{
		close(fd_c[1]);
		close(fd_p[0]);
		nbr = 5;
		if (write(fd_p[1], &nbr, sizeof(nbr)) == -1)
			return (1);
		if (read(fd_c[0], &nbr, sizeof(nbr)) == -1)
			return (1);
		close(fd_c[0]);
		close(fd_p[1]);
		printf("somme finale : %d\n", nbr);
		wait(NULL);
	}
}
