/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:57:48 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 09:30:43 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAG_HPP
# define FRAGTRAG_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :

		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &cpy);
		~FragTrap(void);

	void	highFivesGuys(void) const;
	void	attack(const std::string &target);

};

#endif