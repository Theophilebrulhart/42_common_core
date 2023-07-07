/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 17:28:01 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

int main (void)
{
    Sample instance;
    Sample *instancep = &instance;

    int     Sample::*p = NULL;
    void    (Sample::*f)(void) const;

    p = &Sample::foo;

    std::cout << "foo : " << instance.foo << std::endl;
    instance.*p = 42;
    std::cout << "foo : " << instance.foo << std::endl;
    instancep->*p = 82;
    std::cout << "foo : " << instance.foo << std::endl;

    f = &Sample::bar;

    (instance.*f)();
    (instancep->*f)();
    return (0);
}