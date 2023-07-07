/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whichType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:28:17 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 13:05:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

bool	isChar(std::string literal)
{
	if (literal.length() == 1)
	{
		char c = literal[0];
		if (c > 31 && c <= 127 && !isdigit(c))
			return (true);
	}
	return (false);
}

bool	isInt(std::string literal)
{	
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[i] == '-')
			continue ;
		if (isdigit(literal[i]))
			continue ;
		return (false);
	}
	return (true);
}

int	isFloat(std::string literal)
{
	int	sign = 0;
	int	dote = 0;
	int	f	 = 0;
	int pres = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '-' || literal[i] == '+')
		{
			if (i != 0)
				return (false);
			continue ;
		}
		if (literal[i] == '.')
		{
			dote++;
			continue ;
		}
		if (literal[i] == 'f')
		{	
			if (i != literal.length() - 1)
				return (false);
			f++;
			continue ;
		}
		if (!isdigit(literal[i]))
			return (false);
		if (isdigit(literal[i]) && dote == 1)
			pres++;
			
	}
	if (sign <= 1 && dote == 1 && f == 1)
		return (pres);
	return (false);
}

int	isDub(std::string literal)
{
	int	sign = 0;
	int	dote = 0;
	int	pres = 0;

	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '-' || literal[i] == '+')
		{
			if (i != 0)
				return (false);
			continue ;
		}
		if (literal[i] == '.')
		{
			dote++;
			continue ;
		}
		if (!isdigit(literal[i]))
			return (false);
		if (isdigit(literal[i]) && dote == 1)
			pres++;
	}
	if (sign <= 1 && dote == 1)
		return (pres);
	return (false);
}

std::string	whichType(std::string literal)
{
	if (isChar(literal))
		return ("char");
	if (isInt(literal))
		return ("int");
	if (isFloat(literal))
		return ("float");
	if (isDub(literal))
		return ("double");
	if (literal == "-inff" || literal == "+inff" || literal == "nanf"
			|| literal == "-inf" || literal == "+inf" || literal == "nan")
		return (literal);
	return ("NULL");
}