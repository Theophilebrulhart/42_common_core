/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:40:36 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 12:03:39 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>

class AForm;

class Bureaucrat
{
	public : 

		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &cpy);
		Bureaucrat &operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);

		void		setGrade(int	i);
		int			getGrade(void) const;
		std::string	getName(void) const;
		void		incrementGrade();
		void		decrementGrade();
		void		signAForm(AForm &AForm);

		void		executeForm(AForm const &form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private :

		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);

# include "AForm.hpp"

#endif