/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:49:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "😽 you created an wrong anonymous cat\n\n";
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Ho no... Youre wrong 😽 is dead\n\n";
	return ;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "😽 WRONG MIAAAAOUM\n\n";
	return ;
}