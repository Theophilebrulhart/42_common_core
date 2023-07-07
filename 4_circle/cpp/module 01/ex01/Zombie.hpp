/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:52:21 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 13:05:44 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie
{
	public :

		Zombie();
		~Zombie();
		void	announce(void) const;
		void	setName(std::string name);

	private :

	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);
#endif
