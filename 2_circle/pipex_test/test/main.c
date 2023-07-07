/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:14:27 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/05/03 16:48:22 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	//int	fd_infile;
	int	fd_outfile;
	int	fd_pipe[2][2];
	int	id_child1;
	int	id_child2;
	int	id_child3;
	(void)argc;
	(void)argv;
	
	if (pipe(fd_pipe[0]) < 0)
		return (1);
	if (pipe(fd_pipe[1]) < 0)
		return (1);
	id_child1 = fork();
	if (id_child1 < 0)
		return (1);
	if (id_child1 == 0)
	{
		close(fd_pipe[1][1]);
		close(fd_pipe[1][0]);
		fd_pipe[0][0] = open("infile", O_RDONLY, 0777);
		if (fd_pipe[0][0] == -1)
			return (1);
		dup2(fd_pipe[0][0], STDIN_FILENO);
		close(fd_pipe[0][0]);
		dup2(fd_pipe[0][1], STDOUT_FILENO);
		close(fd_pipe[0][1]);
		execlp("grep", "grep", "sa", NULL);
	}
	id_child2 = fork();
	if (id_child2 < 0)
		return (1);
	if (id_child2 == 0)
	{
		close(fd_pipe[0][1]);
		close(fd_pipe[1][0]);
		dup2(fd_pipe[0][0], STDIN_FILENO);
		close(fd_pipe[0][0]);
		dup2(fd_pipe[1][1], STDOUT_FILENO);
		close(fd_pipe[1][1]);
		execlp("grep", "grep", "salu", NULL);
	}
	id_child3 = fork();
	if (id_child3 < 0)
		return (1);
	if (id_child3 == 0)
	{
		close(fd_pipe[0][0]);
		close(fd_pipe[0][1]);
		dup2(fd_pipe[1][0], STDIN_FILENO);
		close(fd_pipe[1][0]);
		fd_outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fd_outfile, STDOUT_FILENO);
		close(fd_pipe[1][1]);
		execlp("grep", "grep", "salut", NULL);
	}
	close(fd_pipe[0][0]);
	close(fd_pipe[1][1]);
	close(fd_pipe[1][0]);
	close(fd_pipe[0][1]);
	waitpid(id_child1, NULL, 0);
	waitpid(id_child2, NULL, 0);
	waitpid(id_child3, NULL, 0);
	return (0);
}
