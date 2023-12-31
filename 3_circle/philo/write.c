/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:42:30 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 16:02:25 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	write_state_suite(t_main *main, int i, int state, long long now)
{
	if (state == 3 && main->dead == 0)
		printf("%s%lld %d is sleeping\n", "\e[1;34m",
			now, main->philo[i].philo_id + 1);
	if (state == 4 && main->dead == 0)
		printf("%s%lld %d is thinking\n", "\033[0;35m",
			now, main->philo[i].philo_id + 1);
	if (state == 6 && main->dead == 1)
	{
		printf("\n%s%lld each philosopher have eaten %d times\n\n", "\033[0;37m",
			now, main->state.max_eat);
		return (1);
	}
	return (0);
}

int	write_state(t_main *main, int i, int state)
{
	long long	now;

	now = time_to_die(main->t0);
	pthread_mutex_lock(&main->write);
	if (state == 5 && main->dead == 1)
	{
		printf("\n%s%lld %d died\n\n", "\e[0;38;5;199m",
			now, main->philo[i].philo_id + 1);
		return (1);
	}
	if (state == 1 && main->dead == 0)
		printf("%s%lld %d has taken a fork\n", "\e[0;32m",
			now, main->philo[i].philo_id + 1);
	if (state == 2 && main->dead == 0)
		printf("%s%lld %d is eating\n", "\033[0;33m",
			now, main->philo[i].philo_id + 1);
	else
		write_state_suite(main, i, state, now);
	pthread_mutex_unlock(&main->write);
	return (0);
}
