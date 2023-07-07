/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:57:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 15:55:14 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(void)
{
    return ;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
   return ;
}

ASpell:: ASpell(ASpell const &cpy)
{
	*this = cpy;
    return ;
}

ASpell &ASpell::operator=(ASpell const &rhs)
{
    if (this != &rhs)
    {
		_name = rhs._name;
		_effects = rhs._effects;
    }
    return (*this);
}

ASpell::~ASpell(void)
{
    return ;
}

std::string const ASpell::getEffects(void) const
{
	return (_effects);
}

std::string const ASpell::getName(void) const
{
	return (_name);
}

void	ASpell::lauch(ATarget const &target) const
{
	target.getHitBySpell(*this);
	return ;
}
