/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:14 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 12:09:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "🐶 you created an anonymous Dog\n\n";
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Ho no... Youre 🐶 is dead\n\n";
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "🐶 WOAAAFF\n\n";
	return ;
}