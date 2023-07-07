/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/16 16:54:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Sample::Sample(void) : public_foo(42), _private_foo(84)
{
    std::cout << "Constructor called" << std::endl;
	std::cout << "public foo dans constructor : " << this->public_foo << std::endl;
	std::cout << "private foo dans constructor : " << this->_private_foo << std::endl;
	this->public_bar();
	this->_private_bar();
    return ;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void	Sample::public_bar(void) const
{
	std::cout << "public Member function called" << std::endl;
	return ;
}

void	Sample::_private_bar(void) const
{
	std::cout << "private Member function called" << std::endl;
	return ;
}