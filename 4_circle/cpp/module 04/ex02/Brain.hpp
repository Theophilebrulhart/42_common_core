/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:41:34 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/13 16:49:41 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain 
{
    public : 

        Brain(void);
        Brain(Brain const &cpy);
        ~Brain(void);

        Brain       &operator=(Brain const &rhs);
        void        setIdea(std::string idea, int i);
        std::string getIdea(int i) const;

        std::string _ideas[100];
};

#endif