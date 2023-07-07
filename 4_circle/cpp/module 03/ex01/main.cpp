/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:15:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/10 14:48:17 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Hubert("Hubert");
	ScavTrap Tom("Tom");

	Tom.attack("Hubert");
	Hubert.takeDamage(20);
	Hubert.guardGate();
	Hubert.attack("Tom");
	Tom.takeDamage(20);
	Tom.beRepaired(3);
	Tom.guardGate();
	Tom.attack("Hubert");
	Hubert.takeDamage(1000000);
	
	return (0);
}