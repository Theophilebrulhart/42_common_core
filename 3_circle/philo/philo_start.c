/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:32:32 by theophilebr       #+#    #+#             */
/*   Updated: 2022/09/01 16:30:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start(void *arg)
{
	t_main	*main;
	int		*ret;

	ret = malloc(sizeof(int));
	main = (t_main *)arg;
	*ret = taking_fork(main, main->thread_id);
	printf("start res : %d\n", *ret);
	return ((void *) ret);
}

void	*dead_checker(void *arg)
{
	t_main	*main;
	int		i;
	int		*ret;

	ret = malloc(sizeof(int));
	main = (t_main *)arg;
	i = 0;
	while (i < main->state.nbr_philo && !main->dead)
	{
		*ret = philo_dead(main, i);
		if (*ret)
			return ((void *) ret);
		i++;
		if (i == main->state.nbr_philo)
			i = 0;
	}
	return ((void *) ret);
}
