/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:06:51 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/04/25 13:26:22 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
int     ft_printf(const char *str, ...);
void    sort_out(va_list arg, char c, int *count);
void    ft_putnbr_base(unsigned int nbr, int *count);
void    ft_putnbr(int nbr, int *count);
void    ft_putstr(char *str, int *count);
void    ft_putchar(int ascii, int *count);

#endif