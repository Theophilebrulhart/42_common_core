/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:45:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/16 16:10:36 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrate constructor par default called\n";
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	std::cout << "Bureaucrate " << _name << " constructor par parametre called with grade " << grade << std::endl;
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Please give a lower grade for " << _name << " / " << e.what()<< "\n";
	}
		
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Please give a higher grade for " << _name << " / " << e.what() <<"\n";
	}
		
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : _name(cpy._name)
{
	std::cout << "Bureaucrate " << _name << " constructor par copie called\n";
	*this = cpy;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrate " << _name << " destructor called\n";
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return (*this);
}

void	Bureaucrat::setGrade(int	grade)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Please give a lower grade for " << _name << " / " << e.what()<< "\n";
	}
		
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Please give a higher grade for " << _name << " / " << e.what() <<"\n";
	}
	return ;
}

int		Bureaucrat::getGrade() const
{
	return (_grade);
}
std::string	Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade--;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Please give a lower grade for " << _name << " / " << e.what()<< "\n";
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Please give a higher grade for " << _name << " / " << e.what() <<"\n";
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is to Low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is to High");
}

std::ostream & operator<<(std::ostream& o, Bureaucrat const &rhs)
{
	o << rhs.getName() << ", bureaucrat grade is " << rhs.getGrade();
	return (o);
}