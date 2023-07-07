/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:43:02 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:51:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
	return ;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";
	std::map<std::string, ASpell *>::iterator it_b = _spellBook.begin();
	std::map<std::string, ASpell *>::iterator it_e = _spellBook.end();
	while (it_b != it_e)
	{
		delete it_b->second;
		++it_b;
	}
	return ;
}

std::string const Warlock::getName(void) const
{
	return (_name);
}

std::string const Warlock::getTitle(void) const
{
	return (_title);
}

void			Warlock::setTitle(std::string const title)
{
	_title = title;
	return ;
}

void			Warlock::introduce(void) const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
	return ;
}

void	Warlock::learnSpell(ASpell *spell)
{
	_spellBook.learnSpell(spell);
	return ;
}

void	Warlock::forgetSpell(std::string spell)
{
	_spellBook.forgetSpell(spell);
	return ;
}

void	Warlock::launchSpell(std::string spell, ATarget &target)
{
	ATarget const *test = 0;
	if (test == &target)
		return ;
	ASpell *tmp = _spellBook.createSpell(spell);
	if (tmp)
		tmp->launch(target);
}