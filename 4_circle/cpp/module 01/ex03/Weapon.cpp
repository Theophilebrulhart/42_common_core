/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:24:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 15:39:58 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon)
{
	std::cout << "\n** NEW WEAPON **\n" << this->_type << "\n\n";
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "\n** WEAPON LOST **\n\n";
	return ;
}

std::string const &Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string weapon)
{
	std::cout << "\n** CHANGE WEAPON **\n" << weapon << "\n\n";
	this->_type = weapon;
	return ;
}