/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:50:21 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:03:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
#define FIREBALL_HPP
#include "ASpell.hpp"

class Fireball : public ASpell
{
	public :
	
		Fireball();
		~Fireball();

		virtual ASpell *clone(void) const;
};

#endif