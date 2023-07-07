/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:19:20 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 16:48:40 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent                    {public : virtual ~Parent(void){};}; //Pour utiliser un dynamic cast, il faut avoir une methode
class Child1 : public Parent    {};
class Child2 : public Parent    {};

class Unrelated                 {};

int main(void)
{
    Child1 a;                                       //Instance de référence

    Parent  *b = &a;                              //Implicite reinterpretation cast -> upcast
    Child1  *c = dynamic_cast<Child1 *>(b);       
    if (c == NULL)
        std::cout << "cast convertion failed\n";
    else
        std::cout << "cast convertion succeded\n";

    try
    {
        Child2  &d = dynamic_cast<Child2 &>(*b);
        std::cout << "cast convertion succedded\n";
    }
    catch(const std::bad_cast& e)
    {
        std::cerr << "cast convertion failed "<< e.what() << '\n';
    }

    try
    {
        
        Child1  &e = dynamic_cast<Child1 &>(*b);
        std::cout << "cast convertion succedded\n";
    }
    catch(const std::bad_cast& cast)
    {
        std::cerr << "cast convertion failed " << cast.what() << '\n';
    }
    

}