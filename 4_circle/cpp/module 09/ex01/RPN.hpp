/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:09:35 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/21 16:15:06 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream> 
# include <stack>
# include <sstream>
# include <cctype>


class RPN
{
    public:
        RPN(std::string list);
        RPN(RPN const &cpy);
        RPN &operator=(RPN const &rhs);
       ~RPN(void);

       void operation(std::string list);

    private:

        std::stack<double> _stack;
        RPN(void);
};

#endif