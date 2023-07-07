/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:30:53 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 16:05:02 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template <typename T>
void	printArray(T *array, int size)
{
	int t;
	std::cout << "{ ";
	for (int i = 0; i < size - 1; i++)
	{
		std::cout << array[i] << ", ";
		t = i;
	}
	t++;
	std::cout << array[t];
	std::cout << " }\n";
}

template <typename T>
void	iter(T *array, int size, void (*func) (T &array))
{
	for (int i = 0; i < size; i++)
		func(array[i]);
	printArray<T>(array, size);
}

template <typename T>
void	changeToAValue(T &value)
{
	value = 'a';
}
