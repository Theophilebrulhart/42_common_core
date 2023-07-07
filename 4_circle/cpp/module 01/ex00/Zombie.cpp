/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:20:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 12:45:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "\n** A ZOMBIE APPEARED **\n\n";
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "\n** GUNSHOT **\n\n" << this->_name << ": BHEUUUUHEHEUHEU\n\n";
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