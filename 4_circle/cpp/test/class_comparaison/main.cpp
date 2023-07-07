/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 16:45:57 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

int main (void)
{
    Sample instance(42);
    Sample instance2(42);

    if (&instance == &instance)
        std::cout << "addresse instance && instance are equal" << std::endl;
    else
        std::cout << "addresse instance && instance are NOT equal" << std::endl;
    if (&instance == &instance2)
        std::cout << "addresse instance && instance2 are equal" << std::endl;
    else
        std::cout << "addresse instance && instance2 are NOT equal" << std::endl;
    if (instance.comparefoo(&instance) == 0)
        std::cout << "foo instance && foo instance are equal" << std::endl;
    else
        std::cout << "foo instance && foo instance are NOT equal" << std::endl;
    
    if (instance.comparefoo(&instance2) == 0)
        std::cout << "foo instance && foo instance2 are equal" << std::endl;
    else
        std::cout << "foo instance && foo instance2 are NOT equal" << std::endl;
    return (0);
}