/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:31:20 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/16 16:13:11 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat Michel("MICHEL", 4);

	std::cout << Michel << std::endl;
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	Michel.incrementGrade();
	std::cout << Michel << std::endl;
	Michel.incrementGrade();
	std::cout << Michel << std::endl;

	std::cout << "\n";
	Bureaucrat Claude("Claude", 300);
	Claude.setGrade(100);
	std::cout << Claude << std::endl;
	Michel.setGrade(400);
	std::cout << Claude << std::endl;

	std::cout << "\n";
	Bureaucrat	Hubert("Hubert", 147);
	std::cout << Hubert << std::endl;
	Hubert.decrementGrade();
	std::cout << Hubert << std::endl;
	Hubert.decrementGrade();
	std::cout << Hubert << std::endl;
	Hubert.decrementGrade();
	std::cout << Hubert << std::endl;
	Hubert.decrementGrade();
	std::cout << Hubert << std::endl;
	Hubert.decrementGrade();
	std::cout << Hubert << std::endl;
	Hubert.decrementGrade();

	return (0);
}

// int main() {
// 	{
// 		std::cout << "normal case" << std::endl;
// 		try {
// 			Bureaucrat test = Bureaucrat("mitch", 20);
// 			Bureaucrat test2 = test;
// 			Bureaucrat test3 = Bureaucrat("boby", 20);
// 			std::cout << test2 << std::endl;
// 			std::cout << test3 << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooLowException &gtle)
// 		{
// 			std::cout << gtle.what() << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooHighException &gthe)
// 		{
// 			std::cout << gthe.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		std::cout << "edge case 1" << std::endl;
// 		try {
// 			Bureaucrat test = Bureaucrat("low", 150);
// 			std::cout << test << std::endl;
// 			Bureaucrat test2 = Bureaucrat("high", 1);
// 			std::cout << test2 << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooLowException &gtle)
// 		{
// 			std::cout << gtle.what() << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooHighException &gthe)
// 		{
// 			std::cout << gthe.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		std::cout << "low case" << std::endl;
// 		try {
// 			Bureaucrat test = Bureaucrat("low", 150);
// 			std::cout << test << std::endl;
// 			test.decrementGrade();
// 			std::cout << "Should not be print!" << std::endl;
// 			std::cout << test << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooLowException &gtle)
// 		{
// 			std::cout << gtle.what() << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooHighException &gthe)
// 		{
// 			std::cout << gthe.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		std::cout << "high case low" << std::endl;
// 		try {
// 			Bureaucrat test = Bureaucrat("high", 1);
// 			std::cout << test << std::endl;
// 			test.incrementGrade();
// 			std::cout << "Should not be print!" << std::endl;
// 			std::cout << test << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooLowException &gtle)
// 		{
// 			std::cout << gtle.what() << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooHighException &gthe)
// 		{
// 			std::cout << gthe.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		std::cout << "out case 1" << std::endl;
// 		try {
// 			Bureaucrat test = Bureaucrat("high", -1);
// 			std::cout << "Should not be print!" << std::endl;
// 			std::cout << test << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooLowException &gtle)
// 		{
// 			std::cout << gtle.what() << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooHighException &gthe)
// 		{
// 			std::cout << gthe.what() << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		std::cout << "out case 2" << std::endl;
// 		try {
// 			Bureaucrat test = Bureaucrat("low", 151);
// 			std::cout << "Should not be print!" << std::endl;
// 			std::cout << test << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooLowException &gtle)
// 		{
// 			std::cout << gtle.what() << std::endl;
// 		}
// 		catch (Bureaucrat::GradeTooHighException &gthe)
// 		{
// 			std::cout << gthe.what() << std::endl;
// 		}
// 	}
// }