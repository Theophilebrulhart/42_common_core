/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:15 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/17 16:02:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	signGradeCheck(Form &form, int signGrade)
{
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150)
		throw Form::GradeTooLowException();
	else
		form.setSignGrade(signGrade);
	return ;
}

void	execGradeCheck(Form &form, int execGrade)
{
	if (execGrade < 1)
		throw Form::GradeTooHighException();
	if (execGrade > 150)
		throw Form::GradeTooLowException();
	else
	{
		form.setExecGrade(execGrade);
	}
		
	return ;
}

Form::Form(void) : _formName("Anonyme Formulaire"),
					_i(0),
					_signGrade(1),
					_execGrade(1)
{
	std::cout << " 📝 Form Constructor par default called\n";
	return ;
}

Form::Form(std::string const formName, int signGrade, int execGrade) : _formName(formName), 
																		_i(0)
{
	std::cout << "📝 Form " << _formName << " Constructor par parametre called\n";
	try
	{
		signGradeCheck(*this, signGrade);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << " 📝 Please give a lower sign grade for the " << _formName << " Form /" << e.what() << '\n';
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << " 📝 Please give a higher sign grade for the " << _formName << " Form / " << e.what() << '\n';
	}
	try
	{
		execGradeCheck(*this, execGrade);
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << " 📝 Please give a lower execution grade for the " << _formName << " Form / " << e.what() << '\n';
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << " 📝 Please give a higher execution grade for the " << _formName << " Form / " << e.what() << '\n';
	}
	return ;
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		_i = rhs._i;
		_signGrade = rhs._signGrade;
		_execGrade = rhs._execGrade;
	}
	return (*this);
}

Form::Form(Form const &cpy) : _formName(cpy._formName),
								_i(cpy._i),
								_signGrade(cpy._signGrade),
								_execGrade(cpy._execGrade)
{
	std::cout << " 📝 Form " << _formName << " Constructor par copy called\n";
	*this = cpy;
}

Form::~Form(void)
{
	std::cout << " 📝 Form " << _formName << " Destructor called\n";
	return ;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is to High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is to Low");
}

void	Form::setI(bool i)
{
	_i = i;
	return ;
}

void	Form::setSignGrade(int signGrade)
{
	try
	{
		if (signGrade < 1)
			throw Form::GradeTooHighException();
		if (signGrade > 150)
			throw Form::GradeTooLowException();
		else
		{
			_signGrade = signGrade;
			std::cout << " 📝 The sign grade of " << _formName << " has been set to " << _signGrade << std::endl;
		}
			
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << " 📝 You cannot set the sign grade for the " << _formName << " Form to : " << signGrade << " / "  << e.what() << '\n';
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << " 📝 You cannot set the sign grade for the " << _formName << " Form to : " << signGrade << " / " << e.what() << '\n';
	}
	return ;
}

void	Form::setExecGrade(int execGrade)
{
	try
	{
		if (execGrade < 1)
			throw Form::GradeTooHighException();
		if (execGrade > 150)
			throw Form::GradeTooLowException();
		else
		{
			_execGrade = execGrade;
			std::cout << " 📝 The execution grade of " << _formName << " has been set to " << _execGrade << std::endl;
		}
			
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cerr << " 📝 You cannot set the execution grade for the " << _formName << " Form to : " << execGrade << " / " << e.what() << '\n';
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << " 📝 You cannot set the execution grade for the " << _formName << " Form to : " << execGrade << " / " << e.what() << '\n';
	}
	return ;
}

std::string const	Form::getFormName(void) const
{
	return (_formName);
}

bool	Form::getI(void) const
{
	return (_i);
}

int		Form::getSignGrade(void) const
{
	return (_signGrade);
}

int		Form::getExecGrade(void) const
{
	return (_execGrade);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > _signGrade)
			throw Form::GradeTooLowException();
		else
		{
			_i = 1;
			std::cout << bureaucrat.getName() << " signed " << _formName << " Form\n";
		}
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << bureaucrat.getName() << " couldnt sign " << _formName << " because : " << e.what() << '\n';
	}
	return ;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "\n" << rhs.getFormName() << " Form";
	if (rhs.getI())
		o << " is signed.\n";
	else
		o << " is unsigned.\n";
	o << "Only bureaucrat with grade " << rhs.getSignGrade() << " or higher can sign it and only bureaucrate with grade "
	<< rhs.getExecGrade() << " or higher can execute it.\n";
	return (o);
}
