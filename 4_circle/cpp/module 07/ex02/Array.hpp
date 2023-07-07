/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:07:11 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/30 14:09:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
    public :

        Array(void) 
        {
            _array = new T[1];
            std::cout << "An empty array is created\n";
        }

        Array(unsigned int n) : _n(n)
        {
            _array = new T[n];
            for (unsigned int i = 0; i < _n; i++)
                _array[i] = 0;
        }

        Array(const Array &cpy)
        {
            std::cout << "A copy has been created\n";
            _array = NULL;
            *this = cpy;
        }

        Array &operator=(Array const &rhs)
        {
            if (this != &rhs)
            {
                _n = rhs._n;
                if (_array)
                    delete(_array);
                _array = new T[_n];
                for (unsigned int i = 0; i < _n; i++)
                _array[i] = rhs._array[i];
            }
            return (*this);
        }

        ~Array(void)    
        {
            if (_array)
                delete [] _array;
            std::cout << "An array is deleted\n";
        }

        T & operator[](unsigned int n)
        {
            if (n > _n - 1)
                throw std::exception();
            return (_array[n]);
        }

        unsigned int   size() const
        {
            return (_n);
        }

    private :

        unsigned int    _n;
        T               *_array;
};

#endif
