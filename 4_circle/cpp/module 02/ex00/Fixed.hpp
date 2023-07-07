/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:38:32 by tbrulhar          #+#    #+#             */
/*   Updated: 2023/01/09 15:50:40 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
class Fixed
{
	public :

		Fixed(void);
		Fixed(Fixed const & copy);
		~Fixed(void);
		
		Fixed & operator=(Fixed const & rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private : 
		
		int	_raw;
		static int const _bits = 8;

};


#endif