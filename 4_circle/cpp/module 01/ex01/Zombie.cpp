/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:50:03 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 13:08:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "\n** A ZOMBIE APPEARED **\n";
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "\n** GUNSHOT **\n" << this->_name << ": BHEUUUUHEHEUHEU\n\n";
	return ;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}