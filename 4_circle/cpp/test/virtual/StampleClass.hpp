/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampleClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:25:14 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/11 10:55:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAMPLECLASS_H
# define STAMPLECLASS_H
# include <iostream>

class Character
{
    public :

        Character(void);
        ~Character(void);

       virtual void    sayHello(std::string const &target) const;
};

class   Warrior : public Character
{
    public : 

        Warrior(void);
        ~Warrior(void);

        void    sayHello(std::string const &target) const;
};

# endif