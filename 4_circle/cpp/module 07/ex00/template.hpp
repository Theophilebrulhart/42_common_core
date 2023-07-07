/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:20:04 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/24 15:25:29 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	T	tmp;
	tmp = x;
	x = y;
	y = tmp;
	return ;
}

template <typename T>
T	const &max(T const &x, T const &y)
{
	return ((x > y) ? x : y);
}

template <typename T>
T	const &min(T const &x, T const &y)
{
	return ((x < y) ? x : y);
}

