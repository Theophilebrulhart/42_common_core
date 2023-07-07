/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:57:27 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/16 15:08:23 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
void    f1()
{
    try
    {
        //Do some stuff here
        if (/*problem*/)
        {
            throw std::exception();
        }
        else
        {
            //do some stuff here
        }
    }
    catch (std::exception e)
    {
        //Handle your error here
    }
}

void    f2()
{
     //Do some stuff here
        if (/*problem*/)
        {
            throw std::exception();
        }
        else
        {
            //do some stuff here
        }
}

void       f3()
{
    try
    {
        f2();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    f4()
{
    class PEBKACException : public std::exception
    {
        public : 
            virtual const char *what() const throw()
            {
                return ("Problem exists between keyboard and chair");
            }
    };

    try
    {
        f3();
    }
    catch(PEBKACException& e)
    {
        //handle the fact that the user is an idiot;
    }
    catch(std::exception& e)
    {
        //Handle other exceptions that are like std::exception
    }
}