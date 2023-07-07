/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:44:19 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 10:26:16 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	return ;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"),
													ScavTrap(name),
													FragTrap(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	_name = name;
	std::cout << "\n🧟**DIAAAAAA**🧟\n" << this->_name << " WHAT AM I ?!\n\n";
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "\n🧟💀SCUUUUUUV💀🧟\n" << this->_name << " is dead without knowing who he really is...\n\n";
	return ;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "🧟 DiamondTrap " << _name << " is in a existentiel crisis !\n";
	std::cout << "🧟 I AM A DIAMONDTRAP FOR SURE...BUT..SOMETIMES I FEEL LIKE...I'M MORE THAN THAT...IM ALSO A "
	<< ClapTrap::getName() << std::endl << std::endl;
	return ;
}