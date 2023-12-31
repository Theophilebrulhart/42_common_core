/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:21:46 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 16:32:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread_checker(t_main *main)
{
	int	*res;

	if (pthread_mutex_init(&main->m_checker, NULL) != 0)
		return (1);
	if (pthread_create(&main->checker, NULL, &dead_checker, (void *) main) != 0)
		return (1);
	if (pthread_join(main->checker, (void **) &res) != 0)
		return (1);
	if (*res == 1)
	{
		free(res);
		return (1);
	}
	return (0);
}

int	create_threads_follow(t_main *main)
{
	int	*res;
	int	i;

	if (create_thread_checker(main))
		return (1);
	i = 0;
	while (i++ < main->state.nbr_philo)
	{
		if (pthread_join(main->philo[i].thread, (void **) &res) != 0)
			return (1);
		if (*res == 1)
		{
			free(res);
			return (1);
		}
	}
	return (0);
}

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&main->eat, NULL) != 0)
		return (1);
	while (i < main->state.nbr_philo)
	{
		main->thread_id = i;
		if (pthread_create(&main->philo[i].thread, NULL,
				&start, (void *) main) != 0)
			return (1);
		i++;
		my_usleep(50, main);
	}
	if (create_threads_follow(main))
		return (1);
	return (0);
}
