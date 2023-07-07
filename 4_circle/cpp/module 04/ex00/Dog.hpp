/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:19 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 13:26:59 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
# include "Animal.hpp"

class Dog : public Animal
{
	public :

		Dog(void);
		Dog(std::string const &type);
		Dog(Dog const &cpy);
		~Dog(void);

		void	makeSound() const;
};

#endif