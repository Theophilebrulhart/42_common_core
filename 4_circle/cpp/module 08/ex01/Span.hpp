/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:38:15 by theophilebr       #+#    #+#             */
/*   Updated: 2023/02/02 12:18:11 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <algorithm>
# include <vector>
# include <utility>
# include <stdarg.h>

class Span
{
	public :

		Span(void);
		Span(unsigned int size);
		Span(Span const &cpy);
		Span &operator=(Span const &rhs);
		~Span(void);

		void	addNumber(int	value);
		void	addNumbers(unsigned int count, ...);
		void	shortestSpan();
		void	longestSpan() const;
		void	printSpan() const;

	public :

	std::vector<int>	_lst;
	unsigned int		_size;
	unsigned int		_actualSize;
};
#endif
