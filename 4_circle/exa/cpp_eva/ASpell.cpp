/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:54:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 13:45:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell()
{
	return ;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
	return ;
}

ASpell::ASpell(ASpell const &cpy)
{
	*this = cpy;
	return ;
}

ASpell	&ASpell::operator=(ASpell const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_effects = rhs._effects;
	}
	return (*this);
}

ASpell::~ASpell()
{
	return ;å
}

std::string	ASpell::getName(void) const
{
	return (_name);
}

std::string	ASpell::getEffects(void) const
{
	return (_effects);
}

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
	return ;
}
