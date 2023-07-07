/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:23:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 16:23:58 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP
# include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph(void);
       ~Polymorph(void);

        ASpell *clone(void) const;

};

#endif