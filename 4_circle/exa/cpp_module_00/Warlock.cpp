/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:40:21 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:07:05 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
   std::cout << _name << ": This looks like another boring day.\n";
   return ;
}

Warlock::~Warlock(void)
{
    std::cout << _name << ": My job here is done!\n";
    return ;
}

std::string	const &Warlock::getName(void) const
{
	return (_name);
}

std::string const &Warlock::getTitle(void) const
{
	return (_title);
}

void	Warlock::setTitle(std::string const &title)
{
	_title = title;
	return ;
}

void Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
	return ;
}

void	Warlock::learnSpell(ASpell *learnSpell)
{
	_spellBook.learnSpell(learnSpell);
	return ;
}

void	Warlock::forgetSpell(std::string forgetSpell)
{
	_spellBook.forgetSpell(forgetSpell);
	return ;
}

void	Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	ATarget const *test = 0;
	if (test == &target)
		return ;
	ASpell* spell = _spellBook.createSpell(spellName);
	if (spell)
		spell->lauch(target);
	return ;
}