/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:06 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 14:46:56 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :

		Cat(void);
		Cat(std::string const &type);
		Cat(Cat const &cpy);
		~Cat(void);

		Cat			&operator=(Cat const &rhs);
		void		setIdea(std::string idea, int i);
		std::string	getIdea(int i) const;
		void		makeSound() const;
	
	private : 

		Brain	*_brain;
};

#endif