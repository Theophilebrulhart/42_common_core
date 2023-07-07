/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 17:04:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

void    f0()
{
    Sample instance2;

    std::cout << "nbr instance : " << Sample::getInstNbr() << std::endl;
    return ;
}

void    f1()
{
    Sample instance1;
    
    std::cout << "nbr instance : " << Sample::getInstNbr() << std::endl;
    f0();
    std::cout << "nbr instance : " << Sample::getInstNbr() << std::endl;
    return ;
}

int main (void)
{
   std::cout << "nbr instance : " << Sample::getInstNbr() << std::endl;
   f1();
   std::cout << "nbr instance : " << Sample::getInstNbr() << std::endl;
    return (0);
}