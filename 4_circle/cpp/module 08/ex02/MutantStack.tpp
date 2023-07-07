/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:35:06 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/02 13:41:47 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <iostream>
# include <list>
template <typename T>
class MutantStack : public std::stack<T>
{
	public : 

		MutantStack(void)
		{
			std::cout << "A new stack is created\n";
		}

		MutantStack(const MutantStack &cpy)
		{
			std::cout << "A Mutant has been copied\n";
			*this = cpy;
		}

		MutantStack	&operator=(MutantStack const &rhs)
		{
			if (this != &rhs)
			{
				this->c = rhs._c;
			}
			return (*this);
		}
	
		~MutantStack(void)
		{
			std::cout << "A stack has been deleted\n";
		}

		typedef	typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator	end()
		{
			return (this->c.end());
		}
};

#endif