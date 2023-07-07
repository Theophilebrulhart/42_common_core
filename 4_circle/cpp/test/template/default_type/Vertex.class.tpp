/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.class.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:38:16 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 14:55:52 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template <typename T = float> // ca veut dire que si on specifie pas le type, le compilateur prendra un float
class Vertex
{
    public :
        
        Vertex(T const &x, T const &y, T const &z) : _x(x), _y(y), _z(z) {}
        ~Vertex(void) {}

        T const &getX(void) const {return this->_x;}
        T const &getY(void) const {return this->_y;} 
        T const &getZ(void) const {return this->_z;}

    private  :

    T const _x;
    T const _y;
    T const _z;

    Vertex(void);    // mettre le constructor par default en prive fait qu'on est oblige d'utiliser le constructor par copie pour instancier la classe

};

template <typename T>
std::ostream & operator<<(std::ostream &o, Vertex<T> const &rhs)
{
    std::cout.precision(1);
    o << std::setiosflags(std::ios::fixed);
    o << "vertex( ";
    o << rhs.getX() << "; ";
    o << rhs.getY() << "; ";
    o << rhs.getZ() << " )";
    o << "\n";
    return (o);
    
}