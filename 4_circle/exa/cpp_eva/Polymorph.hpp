/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:53:52 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:36:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP
#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public :
    
	Polymorph();
	~Polymorph();

	virtual ASpell *clone(void) const;
};

#endif