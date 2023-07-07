/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:45:25 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/02/21 17:13:46 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP
# include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    public:
        TargetGenerator(void);
        //TargetGenerator();
       
       ~TargetGenerator(void);

       void learnTargetType(ATarget *target);
       void forgetTargetType(std::string const &target);
       ATarget *createTarget(std::string const &target);

    private:

        TargetGenerator(TargetGenerator const &cpy);
        TargetGenerator &operator=(TargetGenerator const &rhs);
        std::map<std::string, ATarget *> arr;

};

#endif