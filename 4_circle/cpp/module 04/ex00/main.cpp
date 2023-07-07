/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:08:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 13:36:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* 	meta = new Animal();
	const Animal* 	DogA = new Dog();
	const Animal* 	CatA = new Cat();
	const Cat*		CatB = new Cat();
	Animal			AnimalA("Cheval");
	
	std::cout << DogA->getType() << " " << std::endl;
	std::cout << CatA->getType() << " " << std::endl;
	CatA->makeSound();
	DogA->makeSound();
	meta->makeSound();
	AnimalA.makeSound();
	
	delete(DogA);
	delete(CatA);
	delete(meta);
	delete(CatB);

	const	WrongAnimal*	WrongCatA = new WrongCat();
	const	WrongAnimal*	WrongAnimalA = new WrongAnimal();
	const	WrongCat*		WrongCatB = new WrongCat();

	std::cout << "It's a " << WrongCatA->getType() << std::endl;
	std::cout << "It's a " << WrongCatB->getType() << std::endl;
	std::cout << "It's a " << WrongAnimalA->getType() << std::endl;

	WrongCatA->makeSound();
	WrongCatB->makeSound();
	WrongAnimalA->makeSound();

	delete(WrongAnimalA);
	delete(WrongCatA);
	delete(WrongCatB);
	
	return 0;
}