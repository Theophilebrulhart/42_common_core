/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:42 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 13:31:28 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Xenomorphe")
{
	std::cout << "You adopted a Xenomorphe 👽 \n\n";
	return ;
}

Animal::Animal(std::string const &type) : _type(type)
{
	std::cout << "You adopted an animal\n";
	std::cout << "Congratulation ! Its's a " << _type << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "HO no.. Youre " << Animal::getType() << " is dead 😢 \n\n";
	return ;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "A " << Animal::getType() << " made a sound\n\n";
	return ;
}