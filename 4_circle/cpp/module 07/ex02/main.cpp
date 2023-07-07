/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:44:30 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 17:24:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
// 		test[1] = 90;
// 		if (test[1] == numbers[1])
// 		{
// 			std::cerr << "Pas profond" << std::endl;
// 			return 1;
// 		}
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "\n\n\n\n\n🤬🤬🤬🤬ARE YOU TRYING TO MAKE ME SEG ??🤬🤬🤬🤬🤬 / " << e.what() << "\n\n\n\n";
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "\n\n\n\n\n🤬🤬🤬🤬ARE YOU TRYING TO MAKE ME SEG ??🤬🤬🤬🤬🤬 / " << e.what() << "\n\n\n\n";
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }

int main(int, char**)
{
    Array<float> numbers(MAX_VAL);
    float* mirror = new float[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<float> tmp = numbers;
        Array<float> test(tmp);
		test[1] = 90;
		if (test[1] == numbers[1])
		{
			std::cerr << "Pas profond" << std::endl;
			return 1;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\n\n\n\n\n🤬🤬🤬🤬ARE YOU TRYING TO MAKE ME SEG ??🤬🤬🤬🤬🤬 / " << e.what() << "\n\n\n\n";
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\n\n\n\n\n🤬🤬🤬🤬ARE YOU TRYING TO MAKE ME SEG ??🤬🤬🤬🤬🤬 / " << e.what() << "\n\n\n\n";
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}