/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:57:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:53:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	public :

		BrickWall();
		~BrickWall();

		virtual ATarget *clone(void) const;
};

#endif