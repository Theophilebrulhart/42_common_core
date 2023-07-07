/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:58:55 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/23 16:51:36 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void	printChar(char c)
{
	std::cout << "char : ";
	if (c > 31 && c <= 127)
		std::cout << c << std::endl;
	else
		std::cout << "is non displayable\n";
	return ;
}

void	printInt(int i)
{
	std::cout << "int : " << i << std::endl;
	return ;
}

void	printFloat(float f, int pres)
{
	std::cout << "float : ";
	std::cout << std::setprecision(pres);
	std::cout << std::fixed;
	std::cout << f << "f" << std::endl;
	return ;
}

void	printDouble(double d, int pres)
{
	std::cout << "double : ";
	std::cout << std::setprecision(pres);
	std::cout << std::fixed;
	std::cout << d << std::endl;
	return ;
}