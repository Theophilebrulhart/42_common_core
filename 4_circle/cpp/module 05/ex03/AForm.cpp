/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:15 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/17 16:02:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void	signGradeCheck(AForm &AForm, int signGrade)
{
	if (signGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150)
		throw AForm::GradeTooLowException();
	else
		AForm.setSignGrade(signGrade);
	return ;
}

void	execGradeCheck(AForm &AForm, int execGrade)
{
	if (execGrade < 1)
		throw AForm::GradeTooHighException();
	if (execGrade > 150)
		throw AForm::GradeTooLowException();
	else
	{
		AForm.setExecGrade(execGrade);
	}
		
	return ;
}

AForm::AForm(void) : _AFormName("Anonyme AFormulaire"),
					_i(0),
					_signGrade(1),
					_execGrade(1)
{
	std::cout << " 📝 AForm Constructor par default called\n";
	return ;
}

AForm::AForm(std::string const AFormName, int signGrade, int execGrade) : _AFormName(AFormName), 
																		_i(0)
{
	std::cout << "📝 AForm " << _AFormName << " Constructor par parametre called\n";
	try
	{
		signGradeCheck(*this, signGrade);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << " 📝 Please give a lower sign grade for the " << _AFormName << " AForm /" << e.what() << '\n';
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << " 📝 Please give a higher sign grade for the " << _AFormName << " AForm / " << e.what() << '\n';
	}
	try
	{
		execGradeCheck(*this, execGrade);
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << " 📝 Please give a lower execution grade for the " << _AFormName << " AForm / " << e.what() << '\n';
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << " 📝 Please give a higher execution grade for the " << _AFormName << " AForm / " << e.what() << '\n';
	}
	return ;
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		_i = rhs._i;
		_signGrade = rhs._signGrade;
		_execGrade = rhs._execGrade;
	}
	return (*this);
}

AForm::AForm(AForm const &cpy) : _AFormName(cpy._AFormName),
								_i(cpy._i),
								_signGrade(cpy._signGrade),
								_execGrade(cpy._execGrade)
{
	std::cout << " 📝 AForm " << _AFormName << " Constructor par copy called\n";
	*this = cpy;
}

AForm::~AForm(void)
{
	std::cout << " 📝 AForm " << _AFormName << " Destructor called\n";
	return ;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is to High");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is to Low");
}

void	AForm::setI(bool i)
{
	_i = i;
	return ;
}

void	AForm::setSignGrade(int signGrade)
{
	try
	{
		if (signGrade < 1)
			throw AForm::GradeTooHighException();
		if (signGrade > 150)
			throw AForm::GradeTooLowException();
		else
		{
			_signGrade = signGrade;
			std::cout << " 📝 The sign grade of " << _AFormName << " has been set to " << _signGrade << std::endl;
		}
			
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << " 📝 You cannot set the sign grade for the " << _AFormName << " AForm to : " << signGrade << " / "  << e.what() << '\n';
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << " 📝 You cannot set the sign grade for the " << _AFormName << " AForm to : " << signGrade << " / " << e.what() << '\n';
	}
	return ;
}

void	AForm::setExecGrade(int execGrade)
{
	try
	{
		if (execGrade < 1)
			throw AForm::GradeTooHighException();
		if (execGrade > 150)
			throw AForm::GradeTooLowException();
		else
		{
			_execGrade = execGrade;
			std::cout << " 📝 The execution grade of " << _AFormName << " has been set to " << _execGrade << std::endl;
		}
			
	}
	catch(AForm::GradeTooHighException& e)
	{
		std::cerr << " 📝 You cannot set the execution grade for the " << _AFormName << " AForm to : " << execGrade << " / " << e.what() << '\n';
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << " 📝 You cannot set the execution grade for the " << _AFormName << " AForm to : " << execGrade << " / " << e.what() << '\n';
	}
	return ;
}

std::string const	AForm::getAFormName(void) const
{
	return (_AFormName);
}

bool	AForm::getI(void) const
{
	return (_i);
}

int		AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int		AForm::getExecGrade(void) const
{
	return (_execGrade);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > _signGrade)
			throw AForm::GradeTooLowException();
		else
		{
			_i = 1;
			std::cout << " 📝  " << bureaucrat.getName() << " signed " << _AFormName << " AForm\n";
		}
	}
	catch(AForm::GradeTooLowException& e)
	{
		std::cerr << " 📝  " << bureaucrat.getName() << " couldnt sign " << _AFormName << " because : " << e.what() << '\n';
	}
	return ;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
	o << "\n" << rhs.getAFormName() << " AForm";
	if (rhs.getI())
		o << " is signed.\n";
	else
		o << " is unsigned.\n";
	o << "Only bureaucrat with grade " << rhs.getSignGrade() << " or higher can sign it and only bureaucrate with grade "
	<< rhs.getExecGrade() << " or higher can execute it.\n";
	return (o);
}
