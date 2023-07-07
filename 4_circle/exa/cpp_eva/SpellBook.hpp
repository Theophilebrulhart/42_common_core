/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:02:09 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:52:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	public :

		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spell);
		ASpell* createSpell(std::string const &spell);

	private :

		SpellBook(SpellBook const &cpy);
		SpellBook	&operator=(SpellBook const &rhs);
		
		std::map<std::string, ASpell *> _spellBook;
};


#endif