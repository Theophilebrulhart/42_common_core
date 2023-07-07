/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:33:27 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 16:35:18 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP
# include <iostream> 
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>
# include "SpellBook.hpp"

class Warlock
{
    public:
        
        Warlock(std::string name, std::string title);
       ~Warlock(void);

       std::string const &getTitle(void) const;
       std::string  const &getName(void) const;
       void                 setTitle(std::string const &title);

       void introduce(void) const;
       void learnSpell(ASpell *learnSpell);
       void forgetSpell(std::string forgetSpell);
       void launchSpell(std::string spellName, ATarget const &target);


    private:

        Warlock(void);
        Warlock(Warlock const &cpy);
        Warlock &operator=(Warlock const &rhs);

        std::string _name;
        std::string _title;
        SpellBook   _spellBook;

};

#endif