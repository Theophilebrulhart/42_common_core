/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampelClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:27:07 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 18:05:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

Student::Student(std::string log) : student_log(log)
{
    std::cout << "Constructor called" << std::endl;
	std::cout << "A student is created : " << this->student_log << std::endl;
    return ;
}

// for array : not possible to pass an argument
Student::Student() : student_log("default")
{
    std::cout << "Constructor called" << std::endl;
	std::cout << "A student is created : " << this->student_log << std::endl;
    return ;
}

Student::~Student(void)
{
    std::cout << "Destructor called" << std::endl;
	std::cout << "A student is deleted : " << this->student_log << std::endl;
    return ;
}