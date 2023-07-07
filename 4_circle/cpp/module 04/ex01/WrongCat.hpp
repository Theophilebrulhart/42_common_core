/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrongcat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:10:06 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 13:26:46 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :

		WrongCat(void);
		WrongCat(std::string const &type);
		WrongCat(WrongCat const &cpy);
		~WrongCat(void);

		void	makeSound() const;
};

#endif