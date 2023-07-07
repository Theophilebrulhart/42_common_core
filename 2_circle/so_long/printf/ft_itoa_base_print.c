/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:44:17 by theophilebr       #+#    #+#             */
/*   Updated: 2021/12/20 17:30:08 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_base_print(unsigned long long int nb, int *count, char x)
{
	char			*base_min;
	char			*base_maj;
	char			c;

	base_min = "0123456789abcdef";
	base_maj = "0123456789ABCDEF";
	if (nb < 0)
		nb *= -1;
	if (nb > 15)
		ft_itoa_base_print(nb / 16, count, x);
	if (x == 'x' || x == 'p')
		c = base_min[nb % 16];
	if (x == 'X')
		c = base_maj[nb % 16];
	write(1, &c, 1);
	*count += 1;
}
