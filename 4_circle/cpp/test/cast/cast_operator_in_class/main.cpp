/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:08:30 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/22 17:15:29 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Main
{
private:
    float   _i;
public:
    Main(float const i) : _i(i) {}

    float   getI()              {return (_i);}

    operator float()            {return (_i);}
    operator int()              {return (static_cast<int>(_i));}
};

int main(void)
{
    Main    a(42.042f);

    float   b = a;
    int     c = a;

    std::cout << a.getI() << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}
