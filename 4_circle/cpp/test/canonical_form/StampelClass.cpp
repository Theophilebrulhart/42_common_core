/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 14:27:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Stample::Stample(void) : _foo(0)
{
    std::cout << "Default Constructor called" << std::endl;
    return ;
}

Stample::Stample(int const n) : _foo(n)
{
    std::cout << "Parametric Constructor called" << std::endl;
    return ;
}

Stample::Stample(Stample const & src)
{
    std::cout << "Copy Constructor called" << std::endl;
    return ;
}

Stample::~Stample(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Stample::getValue(void) const
{
    return (this->_foo);
}

std::ostream & operator<<(std::ostream & o, Stample const & rhs)
{
    o << "The value of foo is : " << rhs.getValue();
    return (o);
}

Stample & Stample::operator=(Stample const & rhs)
{
     std::cout << "Operator assignement called\n";
     if (this != &rhs)
       this->_foo = rhs.getValue();
    return (*this);
}