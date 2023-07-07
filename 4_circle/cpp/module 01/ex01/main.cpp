/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:47:52 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 13:08:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv)
{
	Zombie *Zombies;
	int		N;

	N = 8;
	Zombies = zombieHorde(N, "HUbert");
	for (int i = 0; i < N; i++)
		Zombies[i].announce();
	delete [] Zombies;
	return (0);
}