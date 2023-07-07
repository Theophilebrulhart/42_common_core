/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:08:05 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/21 16:15:28 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
    return ;
}

RPN::RPN(std::string list)
{
   std::cout << "RPN Constructor par parametre called\n";
   operation(list);
   return ;
}

RPN::RPN(RPN const &cpy)
{
    std::cout << " RPN Constructor par copy called\n";
    *this = cpy;
    return ;
}

RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
    {
        _stack = rhs._stack;
    }
    return (*this);
}

RPN::~RPN(void)
{
    std::cout << "RPN Destructor called\n";
    return ;
}

void    RPN::operation(std::string list)
{
    std::stringstream stream(list);
    std::string token;

    while (getline(stream, token, ' '))
    {
        if (token.length() > 1)
        {
            std::cerr << "\e[0;36mError : " << token << " : not a valid number\n\e[0m";
            return ;
        }
        if (isdigit(token[0]))
            _stack.push(stod(token));
        else
        {
            if (_stack.size() < 2) {
                std::cerr << "\e[0;36mError : " << list << " : not a valid RPN.\n\e[0m";
                return ;
            }
            else 
            {
                double nb2 = _stack.top();
                _stack.pop();
                double nb1 = _stack.top();
                _stack.pop();
                switch(token[0])
                {
                    case '+' :
                        _stack.push(nb1 + nb2);
                        break ;
                    case '*' :
                        _stack.push(nb1 * nb2);
                        break ;
                    case '-' :
                        _stack.push(nb1 - nb2);
                        break ;
                    case '/' :
                        _stack.push(nb1 / nb2);
                        break ;
                    default:
                        std::cout << "Invalid operator: " << token[0] << std::endl;
                }
            }
        }
    }
    std::cout << "\e[0;32mresult : " << _stack.top() << "\n\e[0m";
}