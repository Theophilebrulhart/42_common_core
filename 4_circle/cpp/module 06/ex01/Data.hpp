/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:57:37 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 10:46:48 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
# include <iostream> 


class Data
{
    public:
        Data(void);
        Data(Data const &cpy);
        Data &operator=(Data const &rhs);
       ~Data(void);

    int     i;
    char    c;

};

std::ostream & operator<<(std::ostream &o, Data const &rhs);

#endif