/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:09:36 by theophilebr       #+#    #+#             */
/*   Updated: 2023/02/01 16:52:40 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"

int main(void)
{
	{
		std::list<int>	lst;

		lst.push_back(23);
		lst.push_back(33);
		lst.push_back(12);
		lst.push_back(5467);

		std::cout << "Int list test\n";
		try {
			easyfind(lst, 12);
			easyfind(lst, 33);
			easyfind(lst, 23);
			easyfind(lst, 2334);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Element not found in list\n\n";
		}
	}

	std::vector<int>	lst;

	lst.push_back(23);
	lst.push_back(33);
	lst.push_back(12);
	lst.push_back(5467);

	std::cout << "Int vector test\n";
	try {
		easyfind(lst, 12);
		easyfind(lst, 33);
		easyfind(lst, 3482);
		easyfind(lst, 22);
		easyfind(lst, 23);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Element not found in list\n\n";
	}

	return 0;
}