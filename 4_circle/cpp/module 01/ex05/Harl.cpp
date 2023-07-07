/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:23:26 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 18:02:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Mhhm... Excuse me...\n";
	_level[0].key = "DEBUG";
	_level[0].func = &Harl::debug;
	_level[1].key = "INFO";
	_level[1].func = &Harl::info;
	_level[2].key = "WARNING";
	_level[2].func = &Harl::warning;
	_level[3].key = "ERROR";
	_level[3].func = &Harl::error;
	return ;
}

Harl::~Harl(void)
{
	std::cout << "\n\n\n!!!!!! SHUT UP HARL !!!!!!\n\n\n\n";
	return ;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->_level[i].key)
			(this->*_level[i].func)();
	}
	return ;
}

void	Harl::debug(void) const
{
	std::cout << "\n ** DEBUG **\n\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
	return ;
}

void	Harl::info(void) const
{
	std::cout << "\n ** INFO **\n\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
	return ;
}

void	Harl::warning(void) const
{
	std::cout << "\n ** WARNING **\n\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	return ;
}

void	Harl::error(void) const
{
	std::cout << "\n ** ERROR **\n\n";
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
	return ;
}
