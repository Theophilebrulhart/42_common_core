/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:49:36 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/05 20:53:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (1);
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
			ret = 1;
			argv[i] = 0;
			break ;
		}
		if (strncmp(argv[i], ";", 2) == 0)
		{
			ret = 0;
			argv[i] = 0;
			break ;
		}
		i++;
	}
	return (ret);
}

int	cd(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 2)
	{
		write(2, "error: cd: bad arguments", 24);
		return (-1);
	}
	if (chdir(argv[1]))
	{
		write (2, "error: cd: cannot change directory to ", 38);
		write (2, argv[1], ft_strlen(argv[1]));
		write (2, "\n", 1);
		return (-1);
	}
	return (0);
}

void	command(int argc, char **argv, char **envp, int prev, int *fd_prev)
{
	int	i;
	int	fd_next[2];
	pid_t	pid;
	int		exit_status;
	int		next;

	if (argc <= 1)
		return ;
	next = is_pipe(argv);
	if (argv[0])
	{
		if (next && pipe(fd_next) < 0)
		{
			write(2, "error:fatal", 11);
			exit (1);
		}
		if (strncmp(argv[0], "cd", 3) == 0)
			cd(argv);
		else if ((pid = fork()) < 0)
		{
			write (2, "error fatal\n", 13);
			exit (1);
		}
		else if (pid == 0)
		{
			if (prev && dup2(fd_prev[0], 0) < 0)
				exit (-1);
			if (next && dup2(fd_next[1], 1) < 0)
				exit (-1);
			if (execve(argv[0], argv, envp) < 0)
			{
				write (2, "error cannot execute ", 22);
				write (2, argv[0], ft_strlen(argv[0]));
				write (2, "\n", 1);
				exit (-1);
			}
		}
		else
			if (waitpid(pid, &exit_status, 0) < 0)
			{
				write (2, "error fatal\n", 12);
				exit (1);
			}
			if (prev)
				close(fd_prev[0]);
			if (next)
				close(fd_next[1]);
	}
	i = 0;
	while (argv[i])
		i++;
	command(argc -1 -i, argv +1 +i, envp, next, fd_next);
}

int main(int argc, char **argv, char **envp)
{
	int	prev;
	int fd_prev[2];

	prev = 0;
	fd_prev[0] = 0;
	fd_prev[1] = 1;
	command(argc, argv + 1, envp, prev, fd_prev);
}