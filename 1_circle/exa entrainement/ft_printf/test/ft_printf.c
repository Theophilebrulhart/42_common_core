/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrulhar <tbrulhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:29:47 by tbrulhar          #+#    #+#             */
/*   Updated: 2022/11/03 14:00:55 by tbrulhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putchar(int	ascii, int *count)
{
	char	c;

	c = ascii;
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		*count += 6;
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], count);
			i++;
		}
	}
}

void	ft_putnbr(int nbr, int *count)
{
	char	c;
	
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		if (nbr < 0)
		{
			write (1, "-", 1);
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

void	ft_putnbr_base(unsigned int nbr, int *count)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 0)
		nbr = -nbr;
	if (nbr > 15)
		ft_putnbr_base(nbr / 16, count);
	c = base[nbr % 16];
	write (1, &c, 1);
	*count += 1;
}

void	sort_out(va_list arg, char	c, int *count)
{
	if (c == 's')
		ft_putstr(va_arg(arg, char *), count);
	if (c == 'd')
		ft_putnbr(va_arg(arg, int), count);
	if (c == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), count);
}

int	ft_printf(char *str, ...)
{
	int		count;
	int		i;
	va_list arg;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write (1, str + i, 1);
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

int main(void)
{
	ft_printf("salut %s de %d de %x\n", "bite", 3424, 9883247);
}