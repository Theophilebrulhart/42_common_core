/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:17:43 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 12:39:21 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class	Zombie
{
	public :

		Zombie(void);
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);

	private :

		std::string	_name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
#endif