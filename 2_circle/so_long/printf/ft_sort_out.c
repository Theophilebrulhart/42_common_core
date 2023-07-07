/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:50:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/15 14:33:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sort_out(char c, va_list args, int *count)
{
	if (c == 'd' || c == 'i')
		ft_itoa_print(va_arg(args, int), count);
	if (c == 'u')
		ft_unitoa_print(va_arg(args, unsigned int), count);
	if (c == 'c')
		ft_putchar_print(va_arg(args, int), count);
	if (c == 's')
		ft_putstr_print(va_arg(args, char *), count);
	if (c == 'x')
		ft_itoa_base_print(va_arg(args, unsigned int), count, c);
	if (c == 'X')
		ft_itoa_base_print(va_arg(args, unsigned int), count, c);
	if (c == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
		ft_itoa_base_print(va_arg(args, unsigned long long int), count, c);
	}
	if (c == '%')
	{
		*count += 1;
		write (1, "%", 1);
	}
}
