/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:01:17 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 09:34:44 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	return ;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\n🦅**FRAAAAAG**🦅\n" << this->_name << " is ready to get in trouble !\n\n";
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "\n🦅**FROOOOOG**🦅\n" << this->_name << " is dead getting in trouble !\n\n";
	return ;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "🦅👏🏾 FragTrap " << this->_name << " Pleeeease ! Give me an high five !\n\n";
	return ;
}
void    FragTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "🦅💥 FragTrap " << this->_name 
        << " attacks " << target << " , causing " << 
        this->_attackDamage << " points of damage !\n";
        this->_energyPoints--;
        std::cout << "      🔹 Energy left : " << _energyPoints << std::endl << std::endl;
    }
    else
        std::cout << "🦅❌" << " FragTrap " << this->_name
        << " can't attack....\n\n";
    return ;
}
