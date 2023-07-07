/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:22:39 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:51:30 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	public :

		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *target);
		void	forgetTargetType(std::string const &target);
		ATarget	*createTarget(std::string const &type);
	
	private : 
	
		TargetGenerator(TargetGenerator const &cpy);
		TargetGenerator &operator=(TargetGenerator const &rhs);

		std::map<std::string, ATarget *>	targets;
};


#endif