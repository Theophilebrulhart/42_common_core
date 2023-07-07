/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:57:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 10:51:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)
{
    std::cout << " Data Constructor par default called\n";
    return ;
}

Data:: Data(Data const &cpy)
{
    std::cout << " Data Constructor par copy called\n";
	*this = cpy;
    return ;
}

Data &Data::operator=(Data const &rhs)
{
    if (this != &rhs)
    {
		i = rhs.i;
		c = rhs.c;
    }
    return (*this);
}

Data::~Data(void)
{
    std::cout << "Data Destructor called\n";
    return ;
}

std::ostream &operator<<(std::ostream &o, Data const &rhs)
{
    o << "\n";
    o << "Adresse : " << &rhs << std::endl;
    o << "Valeur de i : " << rhs.i << std::endl;
    o << "Valeur de c : " << rhs.c << std::endl;
    o << "\n";
    return (o);
}