/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 17:05:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;
	this->_InstNbr += 1;
    return ;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
	this->_InstNbr -= 1;
    return ;
}

int	Sample::getInstNbr(void)
{
	return (Sample::_InstNbr);
}

int	Sample::_InstNbr = 0;