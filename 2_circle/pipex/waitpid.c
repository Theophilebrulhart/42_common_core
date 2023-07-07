/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:16:18 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/09/08 17:57:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_all(t_pipex *pipex)
{
	int	i;
	int	status;
	int	status_return;

	i = 0;
	while (i < pipex->argc - 3)
	{
		waitpid(pipex->id_child[i], &status, 0);
		 printf("status : %d de l'id %d\n", status, i);
		printf("WIFEXITED : %d\n", WIFEXITED(status));
		if (WIFEXITED(status))
		{
			status_return = WEXITSTATUS(status);
			if (status_return != 0)
				free_all(pipex);
		}
		i++;
	}
}
