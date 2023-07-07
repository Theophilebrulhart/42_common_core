/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:49:40 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << "😽 you created an anonymous cat\n";
	Brain	*newBrain = new Brain;
	_brain = newBrain;
	return ;
}

Cat::Cat(Cat const &cpy)
{
	std::cout << "Constructor cpy cat called\n\n";
	*this = cpy;
}

Cat::~Cat(void)
{
	std::cout << "Ho no... Youre 😽 is dead\n\n";
	delete(_brain);
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "😽 MIAAAAOUM\n\n";
	return ;
}

Cat		&Cat::operator=(Cat const &rhs)
{
	std::cout << "operator = called from cat\n";
	if (this != &rhs)
	{
		delete(_brain);
		Brain *newBrain = new Brain;
		newBrain->Brain::operator=(*rhs._brain);
		_brain = newBrain;
	}
	return (*this);
}

void		Cat::setIdea(std::string idea, int i)
{
	_brain->getIdea(i) = idea;
	return ;
}

std::string Cat::getIdea(int i) const
{
	return (_brain->getIdea(i));
}