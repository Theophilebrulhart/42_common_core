/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:29 by theophilebr       #+#    #+#             */
/*   Updated: 2023/02/02 12:20:31 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _size(0), _actualSize(0)
{
	std::cout << "A default empty span has been created \n";
	return ;
}

Span::Span(unsigned int size) : _size(size), _actualSize(0)
{
	std::cout << "A parametric span with the size " << _size << " has been created\n";
	return ;
}

Span::Span(Span const &cpy)
{
	std::cout << "A copy span has been created\n";
	*this = cpy;
	return ;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_size = rhs._size;
		_actualSize = rhs._actualSize;
		_lst = rhs._lst;
	}
	return (*this);
}

Span::~Span(void)
{
	std::cout << "A span of size : " << _size << " has been deleted\n";
	return ;
}

void	Span::addNumber(int value)
{
	if (_lst.size() < _size)
		_lst.push_back(value);
	else
		throw std::exception();
	return ;
}

void	Span::addNumbers(unsigned int count, ...)
{
	if (count <= _size)
	{
		va_list	arg;

		va_start(arg, count);
		for (unsigned int i = 0; i < count; i++)
		{
			_lst.push_back(va_arg(arg, int));
		}
		va_end(arg);
	}
	else
		throw std::exception();
	
}

void	Span::shortestSpan()
{
	if (_lst.size() < 2)
	{
		throw std::exception();
		return ;
	}
	std::sort(_lst.begin(), _lst.end());
	int	tmp;

	for (unsigned int i = 1; i < _lst.size(); i++)
	{
		int value = _lst[i] - _lst[i - 1];
		if (value < tmp)
			tmp = value;
	}
	std::cout << "The smallest span in range is : " << tmp << "\n";
	return ;
}

void	Span::longestSpan() const
{
	if (_lst.size() < 2)
	{
		throw std::exception();
		return ;
	}
	std::cout << "The longest span in range is : " 
	<< *std::max_element(_lst.begin(), _lst.end()) - *std::min_element(_lst.begin(), _lst.end())
	<< std::endl;
}

void	Span::printSpan() const
{
	int size = _size;
	for (int i = 0; i < size; i++)
	{
		std::cout << _lst[i] << std::endl;
	}
	return ;
}