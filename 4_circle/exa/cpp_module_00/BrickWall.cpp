/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:26:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:14:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall")
{
    return ;
}

BrickWall::~BrickWall(void)
{
    return ;
}

ATarget *BrickWall::clone(void) const
{
    return (new BrickWall());
}