/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 12:08:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "😽 you created an anonymous cat\n\n";
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Ho no... Youre 😽 is dead\n\n";
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "😽 MIAAAAOUM\n\n";
	return ;
}