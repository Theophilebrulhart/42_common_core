/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:04:06 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 16:10:08 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent                    {};
class Child1 : public Parent    {};
class Child2 : public Parent    {};

int main(void)
{
    Child1 a;                       //Instance de référence

    Parent  *b = &a;                //Implicite reinterpretation cast -> upcast
    Parent  *c = (Parent *)&a;      //Explicite reinterpretation cast -> upcast

    Parent  *d = &a;
    Child1  *e = d;                 //Implicite downcast impossible à compiler
    Child2  *f = (Child2 *)d;       //Explicite downcast compile -> FAIS GAFFE

}
