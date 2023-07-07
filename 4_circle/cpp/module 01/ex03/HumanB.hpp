/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:24:22 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 15:35:07 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_H
# define HumanB_H
# include "Weapon.hpp"

class HumanB
{
	public : 

		HumanB(std::string name);
		~HumanB(void);
		void	attack(void);
		void	setWeapon(Weapon *weapon);

	private : 

		std::string _name;
		Weapon 		*_weapon;
};

#endif