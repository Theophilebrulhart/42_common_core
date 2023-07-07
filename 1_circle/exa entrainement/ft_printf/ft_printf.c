/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:05:46 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/25 13:30:48 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    int i;
    int count;
    va_list arg;

    i = 0;
    count = 0;
    va_start(arg, str);
    while (str[i])
    {
        if (str[i] != '%')
        {
            write(1, str + i, 1);
            count++;
        }
        if (str[i] == '%')
        {
            sort_out(arg, str[i + 1], &count);
            i++;
        }
        i++;
    }
    va_end(arg);
    return (count);
}