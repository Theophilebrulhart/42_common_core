/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StampleClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:32:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/12/19 19:02:35 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef STAMPLECLASS_H
# define STAMPLECLASS_H

class Student
{
    public :

        Student(std::string log);
        ~Student(void);

        std::string getLoginRef(void);
        std::string getLoginRefConst(void) const;
        std::string getLoginPtr(void);
       // std::string *getLoginPtrConst (void) const;
    
    private :

        std::string _login;
};

# endif