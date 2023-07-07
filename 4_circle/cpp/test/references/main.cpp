/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:29:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 18:59:34 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "StampleClass.hpp"

int main(void)
{
    Student bob = Student("boby");
    Student const jim = Student("jimmy");

    std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
   // std::cout << *(bob.getLoginPtr()) << " " << *(jim.getLoginPtrConst()) << std::endl;

    bob.getLoginRef() = "bobby par reference";
    std::cout << bob.getLoginRefConst() <<std::endl;
    *(bob.getLoginPtr()) = "bobby par pointeur";
    //std::cout << bob.getLoginPtrConst() << std::endl;

}


// void    addByPtr(std::string *str)
// {
//     *str += " and ponies";
// }

// void    displayByPtr(std::string const *str)
// {
//     std::cout << *str << std::endl;
// }

// void    addByRef(std::string &str)
// {
//     str += " and elephant";
// }

// void    displayByRef(std::string const &str)
// {
//     std::cout << str << std::endl;
// }

// int main(void)
// {
//     std::string str = "I like butterflies";

//     std::cout << str << std::endl;
//     addByPtr(&str);
//     displayByPtr(&str);

//     str = "I like otters";
//     std::cout << str << std::endl;

//     addByRef(str);
//     displayByRef(str);
//     return (0);
// }

// int main (void)
// {
//     int nbr = 42;
//     int *p_nbr = &nbr;
//     int &r_nbr = nbr;

//     std::cout << "normal : " << nbr << " pointeur : " << *p_nbr << " reference : " << r_nbr << std::endl;
//     *p_nbr = 21;
//     std::cout << "normal : " << nbr << " pointeur : " << *p_nbr << " reference : " << r_nbr << std::endl;
//     r_nbr = 84;
//     std::cout << "normal : " << nbr << " pointeur : " << *p_nbr << " reference : " << r_nbr << std::endl;

//     return (0);
// }