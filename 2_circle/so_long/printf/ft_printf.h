/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:57:06 by tbrulhar          #+#    #+#             */
/*   Updated: 2021/11/15 14:22:15 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_sort_out(char c, va_list args, int *count);
void	ft_itoa_print(int nb, int *count);
void	ft_putchar_print(int c, int *count);
void	ft_putstr_print(char *s, int *count);
void	ft_unitoa_print(unsigned int nb, int *count);
void	ft_itoa_base_print(unsigned long long int nbr, int *count, char x);
#endif
