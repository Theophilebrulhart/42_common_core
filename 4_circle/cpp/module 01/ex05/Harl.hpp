/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:23:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 17:55:52 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
# include <iostream>

class Harl
{
	public :

		Harl(void);
		~Harl(void);
		
		typedef struct
		{
			std::string	key;
			void	(Harl::*func)(void) const;
		} level;

		void	complain(std::string level);
	
	private : 

	level 	_level[4];
	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
};
#endif