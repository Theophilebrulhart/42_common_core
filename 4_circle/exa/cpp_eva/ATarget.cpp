/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:04:53 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 13:37:03 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{
    return ;
}

ATarget::ATarget(std::string type) : _type(type)
{
    return ;
}

ATarget::ATarget(ATarget const &cpy)
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

ATarget::~ATarget()
{
    return;
}

std::string const ATarget::getType(void) const
{
    return (_type);
}

void    ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << _type << " has been " << spell.getEffects() << "!\n";
    return ;
}

