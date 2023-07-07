/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 16:17:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Sample::Sample(void) : _private_foo(84)
{
    std::cout << "Constructor called" << std::endl;
	std::cout << "private foo dans constructor : " << this->_private_foo << std::endl;
    return ;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int	Sample::getfoo(void) const
{
	return this->_private_foo;
}

void	Sample::setfoo(int v)
{
	if (v > 0)
		this->_private_foo = 42;
	return ;
}