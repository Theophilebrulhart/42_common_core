/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:18:31 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 14:37:29 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template< typename T>

T max(T const &x, T const &y)
{
	return ((x >= y) ? x : y);
}

int main(void)
{
	int a = 21;
	int b = 42;

	std::cout << "Max of " << a << " and " << b << " is : ";
	std::cout << max<int>(a, b) << std::endl;					// Explicite instantation du template T;
	std::cout << max(a, b) << std::endl;						//Implicite instantation du template T;
}