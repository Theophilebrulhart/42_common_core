/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:22:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/04/21 16:08:39 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    std::cout << " PmergeMe Constructor par default called\n";
    return ;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
   std::cout << "PmergeMe Constructor par parametre called\n";
   for (int i = 1; i < argc; i++)
    {
        std::string stringNb = argv[i];
        for (size_t j = 0; j < stringNb.length(); j++)
        {
            if (!isdigit(stringNb[j]))
            {
                std::cerr << "Error : " << stringNb << " : not positif valid number\n";
                return ;
            }
        }
        try
        {
            _vector.push_back(stoi(stringNb));
            _deque.push_back(stoi(stringNb));
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error : " << stringNb << " : not a valid number\n";
        }
    }
    sortList();
   return ;
}

PmergeMe:: PmergeMe(PmergeMe const &cpy)
{
    std::cout << " PmergeMe Constructor par copy called\n";
    *this = cpy;
    return ;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
        _vector = rhs._vector;
        _deque = rhs._deque;
    }
    return (*this);
}

PmergeMe::~PmergeMe(void)
{
    std::cout << "PmergeMe Destructor called\n";
    return ;
}

template<typename RandomIt>
void insertion_sort(RandomIt begin, RandomIt end) 
{
    for (RandomIt i = begin; i != end; i++) {
        for (RandomIt j = i; j != begin && (*j < *(j - 1)); j--) {
            std::swap(*j, *(j - 1));
        }
    }
}
template<typename RandomIt>
void merge_insertion_sort(RandomIt begin, RandomIt end)
{
    const int threshold = 8;
    if (distance(begin, end) < threshold) {
        insertion_sort(begin, end);
        return;
    }
    RandomIt mid = begin + (end - begin) / 2;
    merge_insertion_sort(begin, mid);
    merge_insertion_sort(mid, end);
    inplace_merge(begin, mid, end);
}



template<typename RandomIt>
void pmergeMe(RandomIt begin, RandomIt end) 
{
    if (begin == end) {
        std::cout << "Error: Empty sequence" << std::endl;
        return;
    }
    merge_insertion_sort(begin, end);
}
void    PmergeMe::sortList()
{

    std::cout << "Before :    ";
    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    clock_t start_v = clock();
    pmergeMe(_deque.begin(), _deque.end());
    clock_t end_v = clock();
    double time_v = (double)(end_v - start_v) / CLOCKS_PER_SEC * 1000;
    std::cout << "After with deque = ";
    for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nTime to process a range of " << _deque.size() << " elements with std::deque => " << time_v << " milisecond";

    clock_t start_d = clock();
    pmergeMe(_vector.begin(), _vector.end());
     clock_t end_d = clock(); // end the timer
    double time_d = (double)(end_d - start_d) / CLOCKS_PER_SEC * 1000;
    std::cout << "\n\n";
    std::cout << "After with vector = ";

    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nTime to process a range of " << _vector.size() << " elements with std::deque => " << time_d << " milisecond\n";

}