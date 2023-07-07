/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:06:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/20 19:13:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->_nbrContact = 0;
	this->_nbrContactMax = 0;
	return ;
}
PhoneBook::~PhoneBook(void)
{
	return ;
}

void	getValue(std::string *value, std::string str)
{
	std::cout << str;
	std::getline(std::cin, *value, '\n');
	return ;
}

void	PhoneBook::addContact(void)
{
	std::string value;

	getValue(&value, "\nWhat's her/his first name ?\nFirstname : ");
	if (value.empty())
		return ;
	this->contacts[_nbrContact].setFirstName(value);
	getValue(&value, "\nWhat's her/his last name ?\nLastname : ");
	if (value.empty())
		return ;
	this->contacts[_nbrContact].setLastName(value);
	getValue(&value, "\nWhat's her/his nickname ?\nNickname : ");
	if (value.empty())
		return ;
	this->contacts[_nbrContact].setNickName(value);
	getValue(&value, "\nWhat's her/his phone number ?\nPhone number : ");
	if (value.empty())
		return ;
	this->contacts[_nbrContact].setPhoneNumber(value);
	getValue(&value, "\nWhat's her/his darkest secret\nDarkest secret : ");
	if (value.empty())
		return ;
	this->contacts[_nbrContact].setSecret(value);
	if (this->_nbrContact == 7)
		this->_nbrContact = -1;
	if (this->_nbrContactMax < 8)
		this->_nbrContactMax++;
	this->_nbrContact++;
	std::cout << "\nNew contact created\n\n";
}

void	printValue(int	i, std::string FirstName, std::string LastName, std::string NickName)
{
	std::cout << "|" << std::setw(10) << std::setfill(' ');
	std::cout << i + 1;
	std::cout << "|" << std::setw(10) << std::setfill(' ');
	if (FirstName.length() > 10)
		std::cout << FirstName.substr(0, 9).append(".");
	else
	std::cout << FirstName;
	std::cout << "|" << std::setw(10) << std::setfill(' ');
	if (LastName.length() > 10)
		std::cout << LastName.substr(0, 9).append(".");
	else
	std::cout << LastName;
	std::cout << "|" << std::setw(10) << std::setfill(' ');
	if (NickName.length() > 10)
	std::cout << NickName.substr(0, 9).append(".") << "|";
	else
	std::cout << NickName << "|";
}

void	PhoneBook::printContacts() const
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";
	for (int i = 0; i < this->_nbrContactMax; i++)
	{
		printValue(i, this->contacts[i].getFirstName(), this->contacts[i].getLastName(), this->contacts[i].getNickName());
		if (i < this->_nbrContactMax - 1)
			std::cout << "\n├──────────┼──────────┼──────────┼──────────┤\n";
	}
	std::cout << "\n└──────────┴──────────┴──────────┴──────────┘\n";
}

void	PhoneBook::searchContact(int i) const
{
	if (i < 1 || i > 8 || this->contacts[i - 1].getFirstName().empty())
	{
		std::cout << "\nUnfortunatly, you dont have enough friends\n\n";
		return ;
	}
	std::cout << "-------\n";
	std::cout << "First name : " << this->contacts[i - 1].getFirstName() << std::endl;
	std::cout << "-------\n";
	std::cout << "Last name : " << this->contacts[i - 1].getLastName() << std::endl;
	std::cout << "-------\n";
	std::cout << "Nickname : " << this->contacts[i - 1].getNickName() << std::endl;
	std::cout << "-------\n";
	std::cout << "Phone number : " << this->contacts[i - 1].getPhoneNumber() << std::endl;
	std::cout << "-------\n";
	std::cout << "Darkest secret : " << this->contacts[i - 1].getSecret() << std::endl;
	return ;
}