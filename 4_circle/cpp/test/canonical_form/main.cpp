/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 14:15:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

int main(void)
{
    Stample instance1;
    Stample instance2(30);
    Stample instance3(instance1);

    std::cout << instance1 << std::endl;
    std::cout << instance2 << std::endl;
    std::cout << instance3 << std::endl;

    instance3 = instance2;
    std::cout << instance3 << std::endl;
    
    return (0);
}
