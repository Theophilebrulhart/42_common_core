/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 16:46:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Sample::Sample(int v) : _private_foo(v)
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int	Sample::getfoo(void) const
{
	return (this->_private_foo);
}

int	Sample::comparefoo(Sample *other) const
{
	if (this->_private_foo < other->getfoo())
		return (-1);
	if (this->_private_foo > other->getfoo())
		return (1);
	return (0);
}