/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:54:19 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 12:08:07 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("An unamed ShrubberyCreationForm", 145, 137)
{
    std::cout << "🌳 ShrubberyCreationForm Constructor par default called\n";
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)
{
    std::cout << "🌳 ShrubberyCreationForm Constructor par parametre called\n";
    return ;
}

ShrubberyCreationForm:: ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
{
    std::cout << "🌳 ShrubberyCreationForm Constructor par copy called\n";
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "🌳 ShrubberyCreationForm Destructor called\n";
    return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::cout << " 🌳 " << executor.getName() << " Wants to execute " << _target << " Form\n";
    
  	std::string trees = "            ,@@@@@@@,\n";
				trees += "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
				trees += " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
				trees += ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
				trees += "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
				trees += "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
				trees += "`&%\\ ` /%&'    |.|        \\ '|8'\n";
				trees += "    |o|        | |         | |\n";
				trees += "    |.|        | |         | |\n";
				trees += " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

	 try
    {
        if (!getI())
            throw std::exception();
        if (executor.getGrade() > AForm::getExecGrade())
            throw AForm::GradeTooLowException();
        else
        {
            std::cout << " 🌳 " << _target << " is signed and " << executor.getName()  << " grade is high enough.. so let's plant some tree\n";
            std::string shrubFile = _target + "_shrubbery";
            std::ofstream ofs (shrubFile.c_str(), std::ofstream::out);
            ofs << trees;
	    }
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cerr << " 🌳 " << executor.getName() << " can't execute " << _target << " / " << e.what() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << " 🌳 Make sure " << _target << " Form is signed \n";
    }
}