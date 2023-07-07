/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:56:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 17:05:11 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void    Contact::setFirstName(std::string value)
{
    this->_firstName = value;
    return ;
}

void	Contact::setLastName(std::string value)
{
	this->_lastName = value;
	return ;
}

void	Contact::setNickName(std::string value)
{
	this->_nickName = value;
	return ;
}

void	Contact::setPhoneNumber(std::string value)
{
	this->_phoneNumber = value;
	return ;
}

void	Contact::setSecret(std::string value)
{
	this->_secret = value;
	return ;
}

std::string	Contact::getFirstName() const
{
	return (this->_firstName);
}

std::string	Contact::getLastName() const
{
	return (this->_lastName);
}

std::string	Contact::getNickName() const
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber() const
{
	return (this->_phoneNumber);
}

std::string Contact::getSecret() const
{
	return (this->_secret);
}