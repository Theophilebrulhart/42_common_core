/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:32:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 12:52:55 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTEGERCLASS_H
# define INTEGERCLASS_H

class Integer
{
    public :

        Integer(int const n);
        ~Integer(void);

        Integer & operator=(Integer const & rhs);
        Integer operator+(Integer const  & rhs) const;
        int getValue(void) const;
    private :

    	int	_n;
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);

# endif