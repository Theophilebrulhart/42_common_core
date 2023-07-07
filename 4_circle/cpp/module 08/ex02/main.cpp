/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:34:11 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/02 14:14:36 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main()
{
	{
		std::cout << "\nMUTANT SCOPE\n\n";
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\nprint the stack\n\n";
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}

	{
		std::cout << "\nLIST SCOPE\n\n";
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.pop_back();
		std::cout << "size " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "\nprint the stack\n\n";
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
	

	return 0;
}