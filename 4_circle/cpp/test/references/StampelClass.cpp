/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 19:09:48 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Student::Student(std::string log) : _login(log)
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

Student::~Student(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}


std::string &Student::getLoginRef()
{
	return (this->_login);
}

std::string &Student::getLoginRefConst() const
{
	return (this->_login);
}

std::string	*Student::getLoginPtr()
{
	return &(this->_login);
}

// std::string *Student::getLoginPtrConst() const
// {
// 	return &(this->_login);
// }