/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 10:54:17 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Character::Character(void)
{
    std::cout << "Constructor Character called" << std::endl;
    return ;
}

Warrior::Warrior(void)
{
    std::cout << "Constructor Warrior called" << std::endl;
    return ;
}

Character::~Character(void)
{
    std::cout << "Destructor Character called" << std::endl;
    return ;
}

Warrior::~Warrior(void)
{
    std::cout << "Destructor Warrior called" << std::endl;
    return ;
}

void Character::sayHello(std::string const &str) const
{
	std::cout << "Hello to you " << str << std::endl;
	return ;
}

void	Warrior::sayHello(std::string const &str) const
{
	std::cout << "Go Fuck yourself " << str << std::endl;
	return ;
}