/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:26:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 16:26:01 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP
# include <iostream> 
# include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy(void);
       ~Dummy(void);

       ATarget *clone(void) const;

    private:

};

#endif