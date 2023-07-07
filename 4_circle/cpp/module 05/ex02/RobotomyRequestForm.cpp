/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:54:02 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 12:08:16 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("An unamed RobotomyRequestForm", 72, 45)
{
    std::cout << "🛠️ RobotomyRequestForm Constructor par default called\n";
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    _target = target;
    std::cout << "🛠️ RobotomyRequestForm Constructor par parametre called\n";
    return ;
}

RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm const &cpy)
{
    std::cout << "🛠️ RobotomyRequestForm Constructor par copy called\n";
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "🛠️ RobotomyRequestForm Destructor called\n";
    return ;
}

void  RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << " 🛠️ " << executor.getName() << " Wants to execute " << _target << " Form\n";
    
    srand (time(NULL));

    try
    {
        if (!getI())
            throw std::exception();
        if (executor.getGrade() > AForm::getExecGrade())
            throw AForm::GradeTooLowException();
        else
        {
            std::cout << " 🛠️ " << _target << " is signed and " << executor.getName()  << " grade is high enough.. so let's try to robotomise " << _target << "\n";
            std::cout << " 🛠️  BBVVVVVVRRRRRRRR ** bruit de perceuse ** \n";
            if (std::rand() % 2)
                std::cout << " 🛠️ " << _target << " has been robotomise successfully\n";
            else
                std::cout << " 🛠️ " << _target << " robotomisation failed.. We are really sorry\n";
        }
    } 
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << " 🛠️ " << executor.getName() << " can't execute " << _target << " / " << e.what() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << " 🛠️ Make sure " << _target << " Form is signed \n";
    }
}