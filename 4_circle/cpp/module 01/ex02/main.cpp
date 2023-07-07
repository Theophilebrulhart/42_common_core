/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:11:47 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/22 13:18:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *pstr = &str;
	std::string &rstr = str;

	std::cout << "\n** ADRESSE **\n\n";
	std::cout << "str : " << &str << std::endl;
	std::cout << "pointeur : " << pstr << std::endl;
	std::cout << "reference : " << &rstr << std::endl;
	
	std::cout << "\n** VALUE **\n\n";
	std::cout << "str : " << str << std::endl;
	std::cout << "pointeur : " << *pstr << std::endl;
	std::cout << "reference : " << rstr << std::endl;
	
	return (0);
}