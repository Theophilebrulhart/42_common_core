/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampleClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:32:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 14:16:40 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef STAMPLECLASS_H
# define STAMPLECLASS_H

class Stample
{
    public :

        Stample(void);  //Default constuctor
        Stample(int const n);   //Parametric constructor
        Stample(Stample const & src); //Copy constructor
        ~Stample(void);

        Stample & operator=(Stample const & rhs);
        int getValue(void) const;

    private :

        int _foo;

};

std::ostream & operator<<(std::ostream & o, Stample const & rhs);

# endif