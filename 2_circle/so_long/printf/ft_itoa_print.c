/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:11:24 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/15 14:13:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_print(int nb, int *count)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
			*count += 1;
		}
		if (nb > 9)
			ft_itoa_print(nb / 10, count);
		c = nb % 10 + '0';
		write(1, &c, 1);
		*count += 1;
	}
}

void	ft_unitoa_print(unsigned int nb, int *count)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_itoa_print(nb / 10, count);
	c = nb % 10 + '0';
	write(1, &c, 1);
	*count += 1;
}
