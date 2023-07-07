/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:31:20 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/17 16:44:14 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form Formu("Creation d'entreprise", 200, 11);
	Form Forma;
	
	Forma = Formu;
	
	std::cout << Forma << std::endl;
	std::cout << Formu << std::endl;

	Formu.setSignGrade(2);
	std::cout << Formu << std::endl;
	Formu.setExecGrade(400);
	Formu.setExecGrade(0);
	Formu.setExecGrade(1);
	Forma.setSignGrade(0);
	Forma.setSignGrade(500);

	Bureaucrat	Claude("Claude", 1);
	Formu.beSigned(Claude);
	Formu.setSignGrade(2);
	std::cout << Formu << std::endl;

	Forma.beSigned(Claude);
	std::cout << Forma << std::endl;
	Forma.setSignGrade(50);
	Forma.beSigned(Claude);

	std::cout << Forma << std::endl;

	Bureaucrat Hubert("Hubert", 150);
	Hubert.signForm(Formu);
	Claude.signForm(Formu);

	
	return (0);
}
