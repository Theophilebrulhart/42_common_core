/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 16:15:25 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

int main (void)
{
    Sample instance;

    std::cout << "ffoo au debut : " << instance.getfoo() << std::endl;
    instance.setfoo(42);
    std::cout << "ffoo apres 42 : " << instance.getfoo() << std::endl;
    instance.setfoo(-42);
    std::cout << "ffoo apres -42 : " << instance.getfoo() << std::endl;
    
    return (0);
}