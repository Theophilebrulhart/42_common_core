/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:47:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:14:49 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{
    return ;
}

TargetGenerator::~TargetGenerator(void)
{
    return ;
}

void    TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
        arr.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
    return ;       
}

void    TargetGenerator::forgetTargetType(std::string const &target)
{
    std::map<std::string, ATarget *>::iterator it = arr.find(target);
    if (it != arr.end())
        delete it->second;
    arr.erase(target);
    return ;
}

ATarget    *TargetGenerator::createTarget(std::string const &target)
{
    std::map<std::string, ATarget *>::iterator it = arr.find(target);
    if (it != arr.end())
        return arr[target];
    return NULL;
}