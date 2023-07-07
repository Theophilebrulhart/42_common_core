/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/16 16:20:53 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Sample::Sample(int p1, char p2, float p3, float const pi) : a1(p1), c1(p2), f1(p3), pi(pi)
{
    std::cout << "Constructor called" << std::endl;
	std::cout << "a1 : " << this->a1 << std::endl;
	std::cout << "c1 : " << this->c1 << std::endl;
	std::cout << "f1 : " << this->f1 << std::endl;
	this->bar();
    return ;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void	Sample::bar(void) const
{
	std::cout << "pi dans bar : " << this->pi << std::endl;
	//this->p1 = 43; impossible de faire une assignation dans une fonction const
}
