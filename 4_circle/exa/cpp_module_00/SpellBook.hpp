/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:29:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:04:57 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP
# include "ASpell.hpp"
# include <map>
# pragma once

class SpellBook
{
    public:
        SpellBook(void);
       ~SpellBook(void);

       void learnSpell(ASpell *spell);
       void forgetSpell(std::string const &spell);
       ASpell *createSpell(std::string const &spell);

    private:

        SpellBook(SpellBook const &cpy);
        SpellBook &operator=(SpellBook const &rhs);
        std::map<std::string, ASpell *> arr;
        
};

#endif