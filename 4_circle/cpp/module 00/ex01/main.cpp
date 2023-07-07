/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:02 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 12:48:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	which_cmd(std::string cmd, PhoneBook *phonebook)
{
	
	if (cmd.compare("ADD") == 0)
	{
		std::cout << "Ho..So you want to add a new contact..Got some new friends ?\n";
		phonebook->addContact();
	}
		
	if (cmd.compare("SEARCH") == 0)
	{
		phonebook->printContacts();
		std::cout << "Fine...Who do you want to reach ?\nChoose your contact between 1 and 8 : ";
		std::getline(std::cin, cmd, '\n');
		phonebook->searchContact(atoi(cmd.c_str()));
	}
	if (cmd.compare("EXIT") == 0)
		return (0);
	return (1);
}

int main(void)
{
	PhoneBook phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "\nYou need something ?\nThen enter your command : ";
		std::getline(std::cin, cmd, '\n');
		if (!which_cmd(cmd, &phonebook))
			break ;
	}
	return (0);
}