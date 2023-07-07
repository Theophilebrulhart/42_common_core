/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:19:50 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/23 17:01:38 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

void	convertToType(std::string literal, std::string type)
{
	if (type == "char")
	{
		char	c = literal[0];
		
		printChar(c);
		printInt(static_cast<int>(c));
		printFloat(static_cast<float>(c), 1);
		printDouble(static_cast<double>(c), 1);
	}
	if (type == "int")
	{
		int	i = std::atoi(literal.c_str());
		
		printChar(static_cast<char>(i));
		printInt(i);
		printFloat(static_cast<float>(i), 1);
		printDouble(static_cast<double>(i), 1);
	}
	if (type == "float")
	{
		float f = std::atof(literal.c_str());
		int pres = isFloat(literal);

		printChar(static_cast<char>(f));
		printInt(static_cast<int>(f));
		printFloat(f, pres);
		printDouble(static_cast<double>(f), pres);
	}
	if (type == "double")
	{
		double d = std::atof(literal.c_str());
		int pres = isDub(literal);

		printChar(static_cast<char>(d));
		printInt(static_cast<int>(d));
		printFloat(static_cast<float>(d), pres);
		printDouble(d, pres);
	}
	if (type == "nan" || type == "-inf" || type == "inf" ||
			 type == "nanf" || type == "-inff" || type == "inff")
	{
		float f;
		if (type == "nan" || type == "nanf")
			f = NAN;
		if (type == "inf" || type == "inff")
			f = INFINITY;
		if (type == "-inf" || type == "-inff")
			f = -INFINITY;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(static_cast<float>(f), 0);
		printDouble(static_cast<double>(f), 0);
	}
	if (type == "NULL")
		std::cout << "Not a literal expression\n";
}

void	convert(std::string literal)
{
	std::string	type;

	type = whichType(literal);
	std::cout << "type at the beginning : " << type << std::endl;
	convertToType(literal, type);
	return ;
}