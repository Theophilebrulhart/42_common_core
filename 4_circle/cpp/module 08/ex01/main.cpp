/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:37:31 by theophilebr       #+#    #+#             */
/*   Updated: 2023/02/02 12:24:42 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		Span spanA(99);
		
		srand(time(NULL));
		try 
		{
			spanA.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cerr << "not enough number in range\n";
		}
		try
		{
			for (int i = 0; i < 10000; i++)
			{
				spanA.addNumber(rand());
			}
		}
		catch (const std::exception &e)
			{
				std::cerr << "Span to small..you can't add any more number to it\n";
			}
		
		try 
		{
			spanA.longestSpan();
		}
		catch (const std::exception &e)
		{
			std::cerr << "not enough number in range\n";
		}
		try 
		{
			spanA.shortestSpan();
		}
		catch (const std::exception &e)
		{
			std::cerr << "not enough number in range\n";
		}
	}

	Span	SpanB(6);
	try
	{
		SpanB.addNumbers(6, 45, 67, 4, 576, 34, 2);
		SpanB.printSpan();
		SpanB.shortestSpan();
		SpanB.longestSpan();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Span to small..you can't add more number to it\n";
	}
	
	return (0);
}