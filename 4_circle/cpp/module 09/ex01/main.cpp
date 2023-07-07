/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:51:50 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/20 13:54:23 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool tokenCheck(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if ((str[i] < 48 || str[i] > 57) && str[i] != '+' &&
            str[i] != '-' && str[i] != '/' && str[i] != '*' && str[i] != ' ')
            return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\e[0;36mError : bad argument\n\e[0m";
        return (1);
    }
    std::string check = argv[1];
    if (!tokenCheck(check))
    {
        std::cerr << "\e[0;36mError : bad argument : unexpected token\n\e[0m";
        return (1);
    }
    RPN rpn(check);
}