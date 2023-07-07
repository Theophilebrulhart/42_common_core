/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:09:54 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 09:06:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public : 

        ScavTrap(void);
        ScavTrap(std::string const &name);
        ScavTrap(ScavTrap const &cpy);
        ~ScavTrap(void);

        void    guardGate() const;
        void	attack(const std::string &target);

};

#endif