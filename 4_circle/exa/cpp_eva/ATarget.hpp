/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:04:26 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 13:42:21 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>

class ASpell;

class ATarget
{
    public :

    ATarget();
    ATarget(std::string type);
    ATarget(ATarget const &cpy);
    ATarget &operator=(ATarget const &rhs);
    virtual ~ATarget();

    std::string const	getType(void) const;
	void				getHitBySpell(ASpell const &spell) const;

	virtual ATarget *clone(void) const = 0;

    private : 
        
        std::string _type;
};
#include "ASpell.hpp"
#endif