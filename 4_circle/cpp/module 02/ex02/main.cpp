/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:37:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 18:23:26 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	Fixed a(19);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "value de a : " << a << std::endl;
	std::cout << "value de ++a : " << ++a << std::endl;
	std::cout << "value de a : "  << a << std::endl;
	std::cout << "value de a++ : "  << a++ << std::endl;
	std::cout << "value de a : " << a << std::endl;
	std::cout << "value de b : "  << b << std::endl;
	std::cout << "value de max (a, b) : " << Fixed::max( a, b ) << std::endl;
	std::cout << "value de min (a, b) : " << Fixed::min( a, b ) << std::endl;
	std::cout << "value de a + b : " << a + b << std::endl;
	std::cout << "value de a - b : " << a - b << std::endl;
	std::cout << "value de a * b : " << a * b << std::endl;
	std::cout <<  "value de a / b : " << a / b << std::endl;
	if (a < b)
		std::cout << "a plus petit\n";
	if (a > b)
		std::cout << "a plus grand\n";
	if ( a <= b)
		std::cout << "a plus petit ou egal a b\n";
	if ( a >= b)
		std::cout << "a plus grand ou egal a b\n";
	return 0;
}