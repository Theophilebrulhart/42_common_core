/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:42:45 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:18:20 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include <map>

class Warlock
{
	public :

		
		Warlock(std::string name, std::string title);
		~Warlock();

		std::string const	getName(void) const;
		std::string const	getTitle(void) const;
		void				setTitle(std::string const title);
		void				introduce(void) const;

		void				learnSpell(ASpell *spell);
		void				forgetSpell(std::string spell);
		void				launchSpell(std::string spell, ATarget &target);


	private : 

		std::string	_name;
		std::string _title;
		SpellBook	_spellBook;
		
		Warlock();
		Warlock(Warlock const &cpy);
		Warlock &operator=(Warlock const &rhs);
};

#endif