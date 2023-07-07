/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:08:56 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 10:57:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "serialize.hpp"

int main(void)
{
	Data		testData;
	uintptr_t	raw;
	Data		*newData;

	testData.i = 56;
	testData.c = 56;

	std::cout << "info testData original : \n";
	std::cout << testData;

	std::cout << "On serialize testdata\n";
	raw = serialize(&testData);

	std::cout << "adresse de raw : " << &raw << "\n";
	newData = deserialize(raw);
	
	std::cout << *newData;
	return (0);
}