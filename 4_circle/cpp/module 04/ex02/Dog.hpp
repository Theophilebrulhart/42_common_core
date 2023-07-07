/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:19 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:50:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public :

		Dog(void);
		Dog(std::string const &type);
		Dog(Dog const &cpy);
		~Dog(void);

		virtual Dog			&operator=(Dog const &rhs);
		void		makeSound() const;
		void		setIdea(std::string idea, int i);
		std::string	getIdea(int i) const;

	private :

		Brain	*_brain;
};

#endif