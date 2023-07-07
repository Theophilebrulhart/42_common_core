/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:18:11 by theophilebr       #+#    #+#             */
/*   Updated: 2021/11/15 14:17:13 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_print(char *s, int *count)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
	}
	if (s != 0)
	{
		while (*s)
		{
			ft_putchar_print(*s, count);
			s++;
		}
	}	
}
