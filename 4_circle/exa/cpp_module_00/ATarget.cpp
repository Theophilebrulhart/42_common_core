/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:08:37 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 15:54:42 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(void)
{
    return ;
}

ATarget::ATarget(std::string type) : _type(type)
{
   return ;
}

ATarget:: ATarget(ATarget const &cpy)
{
	*this = cpy;
    return ;
}

ATarget &ATarget::operator=(ATarget const &rhs)
{
    if (this != &rhs)
    {
		_type = rhs._type;
    }
    return (*this);
}

ATarget::~ATarget(void)
{
    return ;
}

std::string const &ATarget::getType(void) const
{
	return (_type);
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << std::endl;
	return ;
}