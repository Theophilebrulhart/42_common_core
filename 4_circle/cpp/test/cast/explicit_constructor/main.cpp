/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:23:56 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 17:27:16 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class A {};
class B {};

class C
{
public:
                C(A const &test);
    explicite   C(B const &test);
};


void    f(C const &test)
{
    return ;
}

int main(void)
{
    f( A() );      //fonctionne car la convertion implicite entre A et C fonctionne
    f( B() );      //Ne fonctionne pas car le constructor de C par B est explicite
}


