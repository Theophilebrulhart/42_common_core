/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:05 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/06/10 10:52:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipe_allocation(int argc)
{
	int	**fd_pipe;
	int	*fd_single_pipe;
	int	i;

	i = 0;
	fd_pipe = malloc((argc - 4) * sizeof(*fd_pipe));
	if (!fd_pipe)
		return (0);
	while (i < argc - 4)
	{
		fd_single_pipe = malloc(2 * sizeof(*fd_single_pipe));
		if (!fd_single_pipe)
			return (0);
		fd_pipe[i] = fd_single_pipe;
		i++;
	}
	return (fd_pipe);
}

void	close_parent_fd(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	while (i < pipex->argc - 4)
	{
		j = 0;
		while (pipex->fd_pipe[i][j])
		{
			close(pipex->fd_pipe[i][j]);
			j++;
		}
		i++;
	}
}

void	forking_middle_child(t_pipex *pipex)
{
	int	i;

	i = 1;
	while (i < pipex->nbr_pipe)
	{
		pipex->id_child[i] = fork();
		if (pipex->id_child[i] < 0)
			free_all(pipex);
		if (pipex->id_child[i] == 0)
			middle_child(pipex, i);
		i++;
	}
}

void	ft_pipex(t_pipex *pipex)
{
	pipex->nbr_pipe = 0;
	while (pipex->nbr_pipe < pipex->argc - 4)
	{
		if (pipe(pipex->fd_pipe[pipex->nbr_pipe]) < 0)
			free_all(pipex);
		pipex->nbr_pipe++;
	}
	pipex->id_child[0] = fork();
	if (pipex->id_child[0] < 0)
		free_all(pipex);
	if (pipex->id_child[0] == 0)
		first_child(pipex);
	forking_middle_child(pipex);
	pipex->id_child[pipex->argc - 4] = fork();
	if (pipex->id_child[pipex->argc - 4] < 0)
		return ;
	if (pipex->id_child[pipex->argc - 4] == 0)
		last_child(pipex);
	close_parent_fd(pipex);
	wait_all(pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc == 1)
		return (0);
	if (argc < 5)
		error_exit(&pipex, "no such file or directory", argv[1]);
	pipex.env = env;
	pipex.infile = argv[1];
	pipex.outfile = argv[argc - 1];
	pipex.argc = argc;
	pipex.cmd = parsing_command(argc, argv);
	printf("pipex.cmd[0][0] : %s\n", pipex.cmd[0][0]);
	printf("pipex.cmd[0][1] : %s\n", pipex.cmd[0][1]);
	printf("pipex.cmd[1][0] : %s\n", pipex.cmd[1][0]);
	printf("pipex.cmd[1][1] : %s\n", pipex.cmd[1][1]);
	printf("pipex.cmd[1][2] : %s\n", pipex.cmd[1][2]);
	pipex.argv = argv;
	pipex.cmd_path = parsing_command_path(&pipex);
	pipex.id_child = malloc((argc - 3) * sizeof(*pipex.id_child));
	if (!pipex.id_child)
		return (1);
	pipex.fd_pipe = pipe_allocation(argc);
	ft_pipex(&pipex);
	free_all(&pipex);
	return (0);
}
