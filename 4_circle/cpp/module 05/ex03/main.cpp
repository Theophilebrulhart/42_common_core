/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:31:20 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/23 12:07:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat	Claude("Claude", 3);

	Intern someRandomIntern;
	AForm* rrf;
	AForm* failed;
	rrf = someRandomIntern.makeForm("Robotomy request", "Bender");
	failed = someRandomIntern.makeForm("obotomy request", "Bender");


	Claude.signAForm(*rrf);
	

	delete(rrf);
	delete(failed);
	return (0);
}
