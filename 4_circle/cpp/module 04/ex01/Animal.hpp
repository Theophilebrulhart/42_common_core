/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:54 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 15:42:03 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H
# include <iostream>

class Animal
{
	public :

		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &cpy);
		~Animal();
		virtual Animal      &operator=(Animal const &rhs);


		virtual void	makeSound() const;
		std::string		getType() const;

	protected :

		std::string	_type;
};

#endif