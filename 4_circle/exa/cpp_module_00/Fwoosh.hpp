/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:20:58 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 15:50:18 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP
# include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh(void);
       ~Fwoosh(void);

   ASpell *clone(void) const;

};

#endif