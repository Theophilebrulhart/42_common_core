/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:09:54 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:54:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H
# include <iostream>

class AAnimal
{
	public :

		AAnimal(void);
		AAnimal(std::string const &type);
		AAnimal(AAnimal const &cpy);
		virtual ~AAnimal();
		virtual AAnimal      &operator=(AAnimal const &rhs);


		virtual void	makeSound() const = 0;
		std::string		getType() const;

	protected :

		std::string	_type;
};

#endif