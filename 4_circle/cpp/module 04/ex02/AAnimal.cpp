/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:42 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:52:20 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Xenomorphe")
{
	std::cout << "You adopted a Xenomorphe 👽 \n\n";
	return ;
}

AAnimal::AAnimal(std::string const &type) : _type(type)
{
	std::cout << "You adopted an animal\n";
	std::cout << "Congratulation ! Its's a " << _type << std::endl;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "HO no.. Youre " << AAnimal::getType() << " is dead 😢 \n\n";
	return ;
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "A " << AAnimal::getType() << " made a sound\n\n";
	return ;
}

AAnimal      &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "operator = called from animal\n" << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return *this;
}
