/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:20:45 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 16:59:28 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP
# include "ASpell.hpp"


class Fireball : public ASpell
{
    public:
        Fireball(void);
       ~Fireball(void);

		ASpell *clone(void) const;

};

#endif