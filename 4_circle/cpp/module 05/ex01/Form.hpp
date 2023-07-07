/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:11 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/17 16:40:29 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>

class Bureaucrat;

class Form
{
	public :

		Form(void);
		Form(Form const &cpy);
		Form(std::string const formName, int signGrade, int execGrade);
		Form	&operator=(Form const &rhs);
		~Form(void);

		void	setFormName(std::string const name);
		void	setI(bool i);
		void	setSignGrade(int signGrade);
		void	setExecGrade(int setExecGrade);

		std::string const	getFormName(void) const;
		bool				getI(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;

		void				beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public : 
			virtual const char *what() const throw();
	};

	private :

		std::string const	_formName;
		bool				_i;
		int					_signGrade;
		int					_execGrade;
};

std::ostream & operator<<(std::ostream &o, Form const &rhs);

# include "Bureaucrat.hpp"

#endif