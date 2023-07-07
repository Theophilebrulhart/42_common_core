/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:27:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/05 20:51:41 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int	cd(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 2)
		return (-1);
	if (chdir(argv[1]) < 0)
		return (-1);
	return (0);
}

int	is_pipe(char **argv)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (argv[i])
	{
		if (strncmp(argv[i], "|", 2) == 0)
		{
			argv[i] = 0;
			ret = 1;
			break ;
		}
		if (strncmp(argv[i], ";", 2) == 0)
		{
			argv[i] = 0;
			ret = 0;
			break ;
		}
		i++;
	}
	return (ret);
}

void	command(int argc, char **argv, int prev, int *fd_prev, char **envp)
{
	int	i;
	int	fd_next[2];
	int	exit_status;
	int	next;
	pid_t	pid;

	if (argc <= 1)
		return ;
	next = is_pipe(argv);
	if (argv[0])
	{
		if (next && pipe(fd_next) < 0)
			exit (1);
		if (strncmp(argv[0], "cd", 3) == 0)
			cd(argv);
		else if ((pid = fork()) < 0)
			exit (1);
		else if (pid == 0)
		{
			if (prev && dup2(fd_prev[0], 0) < 0)
				exit (-1);
			if (next && dup2(fd_next[1], 1) < 0)
				exit (-1);
			if (execve(argv[0], argv, envp) < 0)
				exit (-1);
		}
		else
			if (waitpid(pid, &exit_status, 0) < 0)
				exit (1);
			if (prev)
				close(fd_prev[0]);
			if (next)
				close(fd_next[1]);
	}
	i = 0;
	while (argv[i])
		i++;
	command (argc - 1 - i, argv + 1 + i, next, fd_next, envp);
}

int main(int argc, char **argv, char **envp)
{
    int prev;
    int fd_prev[2];

    prev = 0;
    fd_prev[0] = 0;
    fd_prev[1] = 1;
    command(argc, argv + 1, prev, fd_prev, envp);
}
