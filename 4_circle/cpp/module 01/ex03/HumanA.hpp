/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:24:16 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 15:32:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_H
# define HumanA_H
# include "Weapon.hpp"

class HumanA
{
	public : 

		HumanA(std::string name, Weapon &type);
		~HumanA(void);
		void	attack(void);

	private : 

		std::string _name;
		Weapon &_weapon;
};

#endif