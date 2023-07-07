/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 12:57:33 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IntegerClass.hpp"

Integer::Integer(int const n) : _n(n)
{
    std::cout << "Constructor called with value  : " << n << std::endl;
    return ;
}

Integer::~Integer(void)
{
    std::cout << "Destructor called with last value : " << this->_n << std::endl;
    return ;
}

Integer & Integer::operator=(Integer const & rhs)
{
    std::cout << "operator assignation called from : " << this->_n << " to : " << rhs.getValue() << std::endl;
    this->_n = rhs.getValue();
    return (*this);
}

Integer Integer::operator+(Integer const & rhs) const
{
    std::cout << "operator addition called with : " << this->_n << " and " << rhs.getValue() << std::endl;
    return Integer(this->_n + rhs.getValue());
}

int   Integer::getValue(void) const
{
    return (this->_n);
}

std::ostream    & operator<<(std::ostream & o, Integer const & rhs)
{
    o << rhs.getValue();
    return (o);
}