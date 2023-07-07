/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:26:57 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/10 12:08:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :_name("An unidentified robot"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constuctor called\n";
    return ;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "\n🤖**CLIC**🤖\n" << _name << " is ready to fight\n\n";
    return;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
    *this = cpy;
    return ;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "\n💀**CLAC**💀\n" << _name << " is dead\n\n";
    return ;
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "💥 ClapTrap " << this->_name 
        << " attacks " << target << " , causing " << 
        this->_attackDamage << " points of damage !\n";
        this->_energyPoints--;
        std::cout << "      🔹 Energy left : " << _energyPoints << std::endl << std::endl;
    }
    else
        std::cout << "❌" << " ClapTrap " << this->_name
        << " can't attack....\n\n";
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "🩸 ClapTrap " << this->_name
    << " took " << amount << " points of damage !\n";
    this->_hitPoints -= amount;
    std::cout << "       ⚙️ Hitpoints left : " << _hitPoints << std::endl << std::endl;
    if (this->_hitPoints <= 0)
        std::cout << "\n💀**CLAC**💀\n" << _name << " is dead\n\n";
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0)
    {
        std::cout << "🛠️ Claptrap " << this->_name
        << " gained " << amount << " hit points\n";
        this->_hitPoints += amount; 
        this->_energyPoints--;
        std::cout << "       ⚙️ Hitpoints left : " << _hitPoints << std::endl;
        std::cout << "      🔹 Energy left : " << _energyPoints << std::endl << std::endl;
    }
    else
        std::cout << "❌" << " ClapTrap " << this->_name
        << " can't be repaired....\n\n";
    return ;
}
