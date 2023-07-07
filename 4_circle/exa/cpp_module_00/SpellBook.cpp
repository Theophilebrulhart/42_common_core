/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:36:09 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:14:37 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
    return ;
}

SpellBook::~SpellBook(void)
{
    return ;
}

void    SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
	{
		arr.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
	}
	return ;
}

void	SpellBook::forgetSpell(std::string const &forgetSpell)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(forgetSpell);
	if (it != arr.end())
		delete	it->second;
	arr.erase(forgetSpell);
	return ;
}

ASpell  *SpellBook::createSpell(std::string const &spell)
{
    std::map<std::string, ASpell *>::iterator it = arr.find(spell);
	if (it != arr.end())
		return arr[spell];
    return NULL;
}

