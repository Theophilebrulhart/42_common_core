/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:16:02 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/21 15:46:01 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>


class PmergeMe
{
    public:

        PmergeMe(int argc, char **argv);
        PmergeMe(PmergeMe const &cpy);
        PmergeMe &operator=(PmergeMe const &rhs);
       ~PmergeMe(void);

        void sortList();
    private:

        std::vector<int>    _vector;
        std::deque<int>     _deque;
        PmergeMe(void);
};

#endif