/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:01:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 12:55:07 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <iostream> 

class Base
{
    public:
    
       virtual ~Base(void);

};

class A : public Base
{

};
class B : public Base
{

};
class C : public Base
{

};
Base    *generate(void);
void	identify(Base &p);
void	identify(Base *p);

#endif