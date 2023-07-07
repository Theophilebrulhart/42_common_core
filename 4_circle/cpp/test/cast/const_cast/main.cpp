/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:50:51 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 17:03:13 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
    int a = 42;                                      //valeur de référence

    int const   *b = &a;                            //Implicite type qualifier cast -> promotion
    int const   *c = const_cast<int *>(&a);         //Explicite type qualifier cast -> promotion

    int const   *d = &a;
    int         *e = d;                                 // HOulaaa faut pas faire de demotion là..tu peux pas passer de mode lecture à ecriture
    int         *f = const_cast<int *>(d);              // ok ca va compilé mais t'as du faire de la merde pour en arriver là
}