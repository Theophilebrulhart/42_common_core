/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:12:00 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/25 13:31:00 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putchar(int ascii, int *count)
{
    char    c;

    c = ascii;
    write(1, &c, 1);
    *count += 1;
}

void    ft_putstr(char *str, int *count)
{
    if (!str)
    {
        write(1, "(null)", 6);
        *count += 6;
    }
    if (str)
    {
        while (*str)
        {
            ft_putchar(*str, count);
            str++;
        }
    }
}

void    ft_putnbr(int nbr, int *count)
{
    char    c;

    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        *count += 11;
    }
    else 
    {
        if (nbr < 0)
        {
            write(1, "-", 1);
            *count += 1;
            nbr = -nbr;
        }
        if (nbr > 9)
            ft_putnbr(nbr / 10, count);
        c = nbr % 10 + '0';
        write (1, &c, 1);
        *count += 1;
    }
}

void    ft_putnbr_base(unsigned int nbr, int *count)
{
    char    c;
    char    *base;

    base = "0123456789abcdef";
    if (nbr < 0)
        nbr = -nbr;
    if (nbr > 15)
        ft_putnbr_base(nbr / 16, count);
    c = base[nbr % 16];
    write(1, &c, 1);
    *count += 1;
}

void    sort_out(va_list arg, char c, int *count)
{
    if (c == 's')
        ft_putstr(va_arg(arg, char *), count);
    if (c == 'd')
        ft_putnbr(va_arg(arg, int), count);
    if (c == 'x')
        ft_putnbr_base(va_arg(arg, unsigned int), count);
}