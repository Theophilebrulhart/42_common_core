/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 16:19:20 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 16:24:17 by theophilebr      ###   ########.fr       */
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
    Child1  *c = b;                                 //Downcast pas compilable
    Child2  *e = static_cast<Child2 *>(b);          //Explicite downcast compile -> FAIS GAFFE

    Unrelated   *f = static_cast<Unrelated *>(&a);  //statid_cast ne permet pas de caster des classes
                                                    //n'appartenant pas au meme arbre de référence

}