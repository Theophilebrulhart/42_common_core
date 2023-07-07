/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:15:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 09:35:44 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap Hubert("James");
	FragTrap Tom("Bond");

	Tom.attack("James");
	Hubert.takeDamage(20);
	Hubert.highFivesGuys();
	Hubert.attack("Bond");
	Tom.takeDamage(20);
	Tom.beRepaired(3);
	Tom.highFivesGuys();
	Tom.attack("James");
	Hubert.takeDamage(1000000);
	
	return (0);
}