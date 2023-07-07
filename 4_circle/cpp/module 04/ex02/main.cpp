/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:58:45 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Dog		DogA = Dog();
	
	// 		DogA.setIdea("pizza", 1);
			
	// 				std::cout << "DOG A first 5 ideas\n\n";

	// 				for (int i = 0; i < 5; i++)
	// 					std::cout << i + 1 << " " << DogA.getIdea(i) << std::endl;
	// 				std::cout << std::endl;
			
	// Dog		DogB = Dog();
	
	// DogB = DogA;
		
	// 	DogA.setIdea("au", 2);
	// 	DogA.setIdea("jambon", 3);

	// 			std::cout << "DOG A first 5 ideas\n\n";

	// 			for (int i = 0; i < 5; i++)
	// 				std::cout << i + 1 << " " << DogA.getIdea(i) << std::endl;
	// 			std::cout << std::endl;

	// 			std::cout << "DOG B first 5 ideas\n\n";
				
	// 			for (int i = 0; i < 5; i++)
	// 				std::cout << i + 1 << " " << DogB.getIdea(i) << std::endl;
	// 			std::cout << std::endl;
	// while (1)
	// {
		
	// }

	///////////////////////////////////////////////////////////////

	AAnimal *AAnimals[10];
	//AAnimal AAnimal = AAnimal(); ->pas possible puisque la classe est abstraite
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "***** DOG NUMBER " << i << " ********\n\n";
		AAnimals[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << "***** CAT NUMBER " << i << " ********\n\n";
		AAnimals[i] = new Cat();
	}
	AAnimals[1]->makeSound();
	AAnimals[5]->makeSound();

	for (int i = 0; i < 10; i++)
		delete(AAnimals[i]);
	return (0);
}