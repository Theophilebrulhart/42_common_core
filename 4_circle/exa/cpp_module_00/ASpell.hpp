/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:48:47 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 15:51:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP
# include <iostream> 

class ATarget;

class ASpell
{
    public:
        ASpell(void);
        ASpell(std::string name, std::string effects);
        ASpell(ASpell const &cpy);
        ASpell &operator=(ASpell const &rhs);
       	virtual ~ASpell(void);

	   std::string	const 	getName(void) const;
	   std::string	const 	getEffects(void) const;
	   virtual ASpell   	*clone(void) const = 0;
       void                 lauch(ATarget const &target) const;

    private:

	std::string _name;
	std::string	_effects;

};

#endif