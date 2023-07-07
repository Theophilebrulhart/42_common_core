/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:30:47 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/20 14:04:32 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# pragma once

class Intern
{
    public:
        Intern(void);
        Intern(Intern const &cpy);
        Intern &operator=(Intern const &rhs);
       ~Intern(void);

	   typedef	struct
	   {
			std::string key;
			AForm		*(Intern::*func)(std::string);
	   } request;

	   AForm *makeForm(std::string requestName, std::string target);

	private : 

		request	_requests[3];
		AForm	*_makeShrub(std::string target);
		AForm	*_makeRobotomy(std::string target);
		AForm	*_makePresidential(std::string target);
};

#endif