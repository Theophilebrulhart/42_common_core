/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:00:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 12:57:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp" 


int main()
{
	srand(time(NULL));
	Base *ptrBase;
	ptrBase = generate();
	Base &refBase = *ptrBase;
	std::cout << "par pointeur : \n";
	identify(ptrBase);
	std::cout << "par ref : \n";

	identify(refBase);
	delete ptrBase;
}