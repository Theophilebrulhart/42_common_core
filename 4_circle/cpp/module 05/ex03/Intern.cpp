/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:32:04 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 14:04:41 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "🚸 Intern Constructor par default called\n";
    _requests[0].key = "Shrubbery request";
    _requests[0].func = &Intern::_makeShrub;
    _requests[1].key = "Robotomy request";
    _requests[1].func = &Intern::_makeRobotomy;
    _requests[2].key = "Presidential request";
    _requests[2].func = &Intern::_makePresidential;
    return ;
}

Intern:: Intern(Intern const &cpy)
{
    std::cout << "🚸 Intern Constructor par copy called\n";
    *this = cpy;
    return ;
}

Intern &Intern::operator=(Intern const &rhs)
{
    return (*this);
}

Intern::~Intern(void)
{
    std::cout << "🚸 Intern Destructor called\n";
    return ;
}

AForm   *Intern::makeForm(std::string requestName, std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (requestName == _requests[i].key)
        {
            std::cout << " 🚸 An intern created a " << requestName << " Form for " << target << "\n";
            return ((this->*_requests[i].func)(target));
        }
            
    }
        std::cout << " 🚸 Your Intern did shit... their is no " << requestName << " Form\n";
    return (NULL);
}

AForm   *Intern::_makeShrub(std::string target)
{
    ShrubberyCreationForm	*FormSchrub = new ShrubberyCreationForm(target);
    return (FormSchrub);
}

AForm   *Intern::_makeRobotomy(std::string target)
{
    RobotomyRequestForm		*FormRobot = new RobotomyRequestForm(target);
    return (FormRobot);
}

AForm   *Intern::_makePresidential(std::string target)
{
   PresidentialPardonForm		*FormPres = new PresidentialPardonForm(target);
    return (FormPres);
}


