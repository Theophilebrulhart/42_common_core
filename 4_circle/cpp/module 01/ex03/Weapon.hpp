/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:24:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/05 15:10:22 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_H
# define WEAPON_H
# include <iostream>

class Weapon
{
	public :

		Weapon(std::string weapon);
		std::string const &getType(void);
		void		setType(std::string weapon);
		~Weapon(void);
	private :

		std::string _type;
};

#endif