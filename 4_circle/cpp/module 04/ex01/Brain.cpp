/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:41:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 15:51:42 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		setIdea("No idea", i);
	std::cout << "Brain constructor called\n\n";
}

Brain::Brain(Brain const &cpy)
{
	std::cout << "Brain copy constructor called\n\n";
	(*this) = cpy;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "operator = called from brain\n\n";
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destructor brain called\n\n";
}

std::string Brain::getIdea(int i) const
{
	return (_ideas[i]);
}

void	Brain::setIdea(std::string idea, int i)
{
	_ideas[i] = idea;
	return ;
}