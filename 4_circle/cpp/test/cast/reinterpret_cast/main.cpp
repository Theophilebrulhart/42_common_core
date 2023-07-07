/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:19:20 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 16:55:14 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent                    {};
class Child1 : public Parent    {};
class Child2 : public Parent    {};

class Unrelated                 {};

int main(void)
{
    Child1 a;                                       //Instance de référence

    Parent  *b = &a;                                //Implicite reinterpretation cast -> upcast
    Child1  *c = reinterpret_cast<Child1 *>(b);     //Compile... a toi de faire gaffe
    Child2  *e = reinterpret_cast<Child2 *>(b);     //Compile... a toi de faire gaffe

    Unrelated   *f = reinterpret_cast<Unrelated *>(&a);   //Compile... a toi de faire gaffe

}