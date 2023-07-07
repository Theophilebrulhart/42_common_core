/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:27:42 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 16:04:10 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int		intArray[] = {1, 2, 3, 4};
	char	charArray[] = {'a', 'b', 'c', 'd'};
	float	floatArray[] = {12.0, 45.09, 23.09, 56.7};
	double	doubleArray[] = {324.98, 342.3, 76.9, 7536.90};

	std::cout << "\nint : \n";
	printArray(intArray, 4);
	iter<int>(intArray, 4, changeToAValue);
	std::cout << "\nchar : \n";
	printArray(charArray, 4);
	iter<char>(charArray, 4, changeToAValue);
	std::cout << "\nfloat : \n";
	printArray(floatArray, 4);
	iter<float>(floatArray, 4, changeToAValue);
	std::cout << "\ndouble : \n";
	printArray(doubleArray, 4);
	iter<double>(doubleArray, 4, changeToAValue);
}