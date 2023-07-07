/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:53:54 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 12:23:03 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("An unamed PresidentialPardonForm", 25, 5)
{
    std::cout << "🗣️ PresidentialPardonForm Constructor par default called\n";
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)
{
    std::cout << "🗣️ PresidentialPardonForm Constructor par parametre called\n";
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy)
{
    std::cout << "🗣️ PresidentialPardonForm Constructor par copy called\n";
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "🗣️ PresidentialPardonForm Destructor called\n";
    return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
	
	std::cout << " 🗣️ " << executor.getName() << " Wants to execute " << _target << " Form\n";

    try
    {
        if (!getI())
            throw std::exception();
        if (executor.getGrade() > AForm::getExecGrade())
            throw AForm::GradeTooLowException();
        else
        {
            std::cout << " 🗣️ " << _target << " is signed and " << executor.getName()  << " grade is high enough.. so let's try forgive " << _target << "\n";
            std::cout << " 🗣️ " << _target << " has been forgiven by Zaphold Beeblebrox\n";
        }
    } 
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << " 🗣️ " << executor.getName() << " can't execute " << _target << " / " << e.what() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << " 🗣️ Make sure " << _target << " Form is signed \n";
    }
}