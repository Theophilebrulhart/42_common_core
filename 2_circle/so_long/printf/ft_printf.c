/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:56:02 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/21 15:35:57 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%' && ++count)
			write(1, str + i, 1);
		if (str[i] == '%')
			ft_sort_out(str[i++ + 1], args, &count);
		i++;
	}
	va_end(args);
	return (count);
}

//  int	main(void)
//  {
//  	//unsigned int	d = -10;
//  	//unsigned int *p = &d;
//  	//printf("\n%d", printf("%p", p));
//  	ft_printf("\n%x", -340);
// }