/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:54:13 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 12:07:51 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"
# pragma once

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(RobotomyRequestForm const &cpy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
       ~RobotomyRequestForm(void);

	   virtual void execute(Bureaucrat const &executor) const ;

    private:

    std::string _target;

};

#endif