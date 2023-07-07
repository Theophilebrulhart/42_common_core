/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:03:50 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 15:07:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->state.nbr_philo)
	{
		pthread_mutex_destroy(&main->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	pthread_mutex_destroy(&main->m_checker);
}

int	error_exit(t_main *main)
{
	int	i;

	i = 0;
	my_usleep(1000, main);
	if (main->philo)
		free(main->philo);
	if (main->fork)
		free(main->fork);
	destroy_mutex(main);
	return (1);
}
