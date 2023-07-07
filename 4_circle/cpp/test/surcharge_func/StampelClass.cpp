/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/05 17:28:23 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Student::Student(void)
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

Student::~Student(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void Student::bar (char const c) const{
    std::cout << "bar with char : " << c << std::endl;
    return ;
}

void Student::bar (int const i) const{
    std::cout << "bar with int : " << i << std::endl;
    return ;
}

void Student::bar (float const f) const{
    std::cout << "bar with flaot : " << f << std::endl;
    return ;
}

void Student::bar (Student const &s) const{
    std::cout << "bar with class : " << std::endl;
    return ;
}