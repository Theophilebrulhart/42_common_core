/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:42 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:49:36 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Wrong Xenomorphe")
{
	std::cout << "You adopted a wrong Xenomorphe 👽 \n\n";
	return ;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
	std::cout << "You adopted a wrong animal\n";
	std::cout << "Congratulation ! Its's a wrong " << _type << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "HO no.. Youre wrong " << WrongAnimal::getType() << " is dead 😢 \n";
	return ;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "A wrong " << WrongAnimal::getType() << " made a sound\n\n";
	return ;
}