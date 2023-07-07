/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:16:03 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 09:06:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	return ;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\n🐲**SCAAAAV**🐲\n" << this->_name << " is ready to protect you !\n\n";
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\n🐲💀SCUUUUUUV💀🐲\n" << this->_name << " is dead protecting you...\n\n";
	return ;
}

void	ScavTrap::guardGate() const
{
	std::cout << "🛡️ ScavTrap " << this->_name << " entered the GATE KEEPER mode\n\n";
	return ;
}

void    ScavTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "🐲💥 ScavTrap " << this->_name 
        << " attacks " << target << " , causing " << 
        this->_attackDamage << " points of damage !\n";
        this->_energyPoints--;
        std::cout << "      🔹 Energy left : " << _energyPoints << std::endl << std::endl;
    }
    else
        std::cout << "🐲❌" << " ScavTrap " << this->_name
        << " can't attack....\n\n";
    return ;
}