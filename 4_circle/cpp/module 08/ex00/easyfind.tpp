/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophilebrulhart <theophilebrulhart@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:11:33 by theophilebr       #+#    #+#             */
/*   Updated: 2023/01/31 15:30:58 by theophilebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
void	easyfind(T listA, int value)
{
	typename T::iterator	it;

	it = find(listA.begin(), listA.end(), value);
	if (it != listA.end())
		std::cout << "value has been found in listA : " << *it << "\n\n";
	else
		throw std::exception();
	return ;
};

#endif