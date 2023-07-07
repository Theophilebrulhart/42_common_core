/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:15:49 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/10 12:03:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Claude("Claude");


	Claude.attack("ton pere");
	Claude.takeDamage(8);
	Claude.beRepaired(200);
	Claude.attack("Alain Berset");
	Claude.beRepaired(100);
	Claude.takeDamage(300);
	Claude.attack("Jean-Hubert");
	Claude.attack("Willy Wonka");
	Claude.attack("Obama");
	Claude.beRepaired(90000);
	Claude.attack("la tour Eiffel");
	Claude.beRepaired(1);
	Claude.attack("ta mere");
	Claude.beRepaired(455);
	Claude.takeDamage(100000000);

	return (0);
}