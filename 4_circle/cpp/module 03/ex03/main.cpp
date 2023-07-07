/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:15:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 10:27:19 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Tom("Bond");
	DiamondTrap	Hubert("James");

	Tom.whoAmI();
	Hubert.whoAmI();
	Tom.attack("James");
	Hubert.takeDamage(20);
	Hubert.guardGate();
	Hubert.highFivesGuys();
	Hubert.attack("Bond");
	Tom.takeDamage(20);
	Tom.beRepaired(3);
	Tom.highFivesGuys();
	Tom.attack("James");
	Hubert.takeDamage(1000000);
	
	return (0);
}