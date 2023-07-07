/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:25:44 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 16:26:40 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP
# include "ATarget.hpp"
# pragma once

class BrickWall : public ATarget
{
    public:
        BrickWall(void);
       ~BrickWall(void);

    ATarget *clone(void) const;
};

#endif