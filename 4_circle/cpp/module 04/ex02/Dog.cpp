/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:14 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:49:38 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << "🐶 you created an anonymous Dog\n";
	Brain	*newBrain = new Brain;
	_brain = newBrain;
	return ;
}

Dog::Dog(Dog const &cpy)
{
	std::cout << "Copy constructor called from dog\n\n";
	(*this) = cpy;
}

Dog::~Dog(void)
{
	std::cout << "Ho no... Youre 🐶 is dead\n\n";
	delete(_brain);
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "🐶 WOAAAFF\n\n";
	return ;
}

Dog		&Dog::operator=(Dog const &rhs)
{
	std::cout << "operator = called from Dog\n\n";
	if (this != &rhs)
	{
		delete(_brain);
		Brain	*newBrain = new Brain;
		newBrain->Brain::operator=( *rhs._brain);
		_brain = newBrain;
	}
	return (*this);
}

void		Dog::setIdea(std::string idea, int i)
{
	_brain->_ideas[i] = idea;
	return ;
}

std::string Dog::getIdea(int i) const
{
	return (_brain->getIdea(i));
}