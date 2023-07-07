/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:03:50 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:07:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP
#include "ASpell.hpp"

class ATarget
{
    public:
        ATarget(void);
        ATarget(std::string type);
        ATarget(ATarget const &cpy);
        ATarget &operator=(ATarget const &rhs);
       virtual ~ATarget(void);

		std::string const	&getType(void) const;

		virtual ATarget 	*clone(void) const = 0;

		void	getHitBySpell(ASpell const &spell) const;

    private:

		std::string _type;
};

#endif