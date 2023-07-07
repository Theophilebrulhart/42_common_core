/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:54:35 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 13:38:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>

class ATarget;

class ASpell
{
	public : 

		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(ASpell const &cpy);
		ASpell &operator=(ASpell const &rhs);
		virtual ~ASpell();

		std::string	getName(void) const;
		std::string	getEffects(void) const;
		void		launch(ATarget const &target) const;

		virtual ASpell *clone(void) const = 0;

	private :

		std::string _name;
		std::string _effects;
};
#include "ATarget.hpp"
#endif