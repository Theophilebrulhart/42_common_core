/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:56 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/05 17:14:33 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_main *main, int i)
{
	long long	time;

	if (main->philo[i].eating == 1)
		return (0);
	time = time_to_die(main->philo[i].die_time);
	if (time == -1)
		return (1);
	if (time > main->state.die_time)
	{
		main->dead = 1;
		write_state(main, i, 5);
		return (1);
	}
	if (main->all_eat == main->state.nbr_philo)
	{
		main->dead = 1;
		write_state(main, i, 6);
		return (1);
	}
	return (0);
}

void	philo_sleep(t_main *main, int i)
{
	write_state(main, i, 3);
	my_usleep(main->state.sleep_time * 1000, main);
	write_state(main, i, 4);
	taking_fork(main, i);
}

int	drop_fork(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->fork[main->philo[i].left_fork]) != 0)
		return (1);
	if (pthread_mutex_unlock(&main->fork[main->philo[i].right_fork]) != 0)
		return (1);
	return (0);
}

int	max_eat_time(t_main *main, int i)
{
	if (main->state.max_eat > 0)
	{
		main->philo[i].nbr_eat++;
		if (main->philo[i].nbr_eat == main->state.max_eat)
			main->all_eat++;
	}
	return (0);
}

int	taking_fork(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->fork[main->philo[i].right_fork]) != 0)
		return (1);
	write_state(main, i, 1);
	if (pthread_mutex_lock(&main->fork[main->philo[i].left_fork]) != 0)
		return (1);
	write_state(main, i, 1);
	write_state(main, i, 2);
	if (max_eat_time(main, i))
		return (1);
	main->philo[i].eating = 1;
	main->philo[i].die_time = get_time();
	my_usleep(main->state.eat_time * 1000, main);
	if (pthread_mutex_lock(&main->eat) != 0)
		return (1);
	main->philo[i].eating = 0;
	if (pthread_mutex_unlock(&main->eat) != 0)
		return (1);
	if (drop_fork(main, i))
		return (1);
	philo_sleep(main, i);
	return (0);
}
