/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:37:30 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 17:35:42 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
	return ;
}

Fixed::Fixed(int const n)
{
	this->_raw = n << this->_bits;
	std::cout << "Int constructor called\n";
	return ;
}

Fixed::Fixed(float const f)
{
	this->_raw = roundf(f * (1 << this->_bits));
	std::cout << "Float constructor called\n";
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
	return ;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignement operated called" << std::endl;
	if (this != &rhs)
		this->_raw = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called\n";
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called\n";
	this->_raw = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	float f = (1 << this->_bits);
	return (this->_raw / f);
}

int	Fixed::toInt(void) const
{
	int i = this->_raw >> this->_bits;
	return (i);
}

std::ostream & operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}
