/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:27:25 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/28 14:38:40 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
	return ;
}

TargetGenerator::~TargetGenerator()
{
	return ;
}

void	TargetGenerator::learnTarget(ATarget *target)
{
	targets.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
	return ;
}

void	TargetGenerator::forgetTarget(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator it = _targets.find(target);
	if (it != targets.end())
		delete it->second;
	targets.erase(target);
	return ;
}

void	TargetGenerator::createTarget(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(target);
	if (it != targets.end())
		return (targets[type]);
	return NULL;
}