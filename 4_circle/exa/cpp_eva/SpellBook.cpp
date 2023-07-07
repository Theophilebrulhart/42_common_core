/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:06:44 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:17:17 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook()
{
	return ;
}

SpellBook::~SpellBook()
{
	return ;
}

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		_spellBook.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
	}
	return ;
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	std::map<std::string, ASpell*>::iterator it = _spellBook.find(spell);
	if (it != _spellBook.end())
		delete it->second;
	_spellBook.erase(spell);
}

ASpell	*SpellBook::createSpell(std::string const &spell)
{
	std::map<std::string, ASpell*>::iterator it = _spellBook.find(spell);
	if (it != _spellBook.end())
		return _spellBook[spell];
	return NULL;
}